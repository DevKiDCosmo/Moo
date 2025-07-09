#include <vector>
#include <mutex>
#include <string>
#include <cstdint>
#include <atomic>
#include <condition_variable>
#include <optional>
#include <algorithm>
#include <memory>
#include <cstring>
#include <cstdlib>
#include "../moo.hpp"
#include "../export.h"

std::vector<std::shared_ptr<moo::FuncCall>> stack;
std::mutex                                  stack_mtx;
std::atomic<int64_t>                        next_id{1};


double moo::executefunc(const std::string& name, const std::vector<int64_t>& params) {
    auto call    = std::make_shared<moo::FuncCall>();
    call->id     = next_id++;
    call->name   = name;
    call->params = params;

    {
        std::lock_guard<std::mutex> lock(stack_mtx);
        stack.push_back(call);
    }

    std::unique_lock<std::mutex> lock(call->mtx);
    call->cv.wait(lock, [&] { return call->done; });
    return call->result.value_or(0.0);
}

// Setzt Ergebnis für Funktionsaufruf mit ID und entfernt ihn
void moo::executedfunc(int64_t id, double result) {
    std::shared_ptr<moo::FuncCall> found;
    {
        std::lock_guard<std::mutex> lock(stack_mtx);
        auto                        it = std::find_if(stack.rbegin(), stack.rend(),
                               [id](const std::shared_ptr<moo::FuncCall>& f) {
                                   return f->id == id;
                               });
        if (it != stack.rend()) {
            found = *it;
            stack.erase(std::next(it).base());
        }
    }
    if (found) {
        {
            std::lock_guard<std::mutex> lock(found->mtx);
            found->result = result;
            found->done   = true;
        }
        found->cv.notify_all();
    }
}

std::vector<const moo::FuncCall*> moo::get_all() {
    std::lock_guard<std::mutex>  lock(stack_mtx);
    std::vector<const FuncCall*> out;
    for (const auto& ptr : stack) out.push_back(ptr.get());
    return out;
}


// C-API
extern "C" {
struct FuncCall {
    int64_t                 id;
    std::string             name;
    std::vector<int64_t>    params;
    std::optional<double>   result;
    std::condition_variable cv;
    bool                    done = false;
    std::mutex              mtx;
};


struct func_call_c {
    int64_t  id;
    char*    name;
    int64_t* params;
    int64_t  param_count;
};

MOOLIB_API double executefunc(const char* name, const int64_t* params, int64_t param_count) {
    std::vector<int64_t> vparams(params, params + param_count);
    return moo::executefunc(name ? name : "", vparams);
}

MOOLIB_API void executedfunc(int64_t id, double result) {
    moo::executedfunc(id, result);
}

MOOLIB_API func_call_c* get_all_func_calls(int64_t* out_count) {
    if (!out_count) return nullptr;
    auto calls       = moo::get_all();
    *out_count       = static_cast<int64_t>(calls.size());
    func_call_c* arr = (func_call_c*)malloc(sizeof(func_call_c) * calls.size());
    if (!arr) return nullptr;
    for (size_t i = 0; i < calls.size(); ++i) {
        arr[i].id = calls[i]->id;
        // Name kopieren
        arr[i].name = (char*)malloc(calls[i]->name.size() + 1);
        if (arr[i].name) std::memcpy(arr[i].name, calls[i]->name.c_str(), calls[i]->name.size() + 1);
        // Parameter kopieren
        arr[i].param_count = static_cast<int64_t>(calls[i]->params.size());
        if (arr[i].param_count > 0) {
            arr[i].params = (int64_t*)malloc(sizeof(int64_t) * arr[i].param_count);
            if (arr[i].params)
                std::memcpy(arr[i].params, calls[i]->params.data(),
                            sizeof(int64_t) * arr[i].param_count);
        } else {
            arr[i].params = nullptr;
        }
    }
    return arr;
}

// Gibt den von get_all_func_calls belegten Speicher wieder frei
MOOLIB_API void free_func_calls(func_call_c* arr, int64_t count) {
    if (!arr) return;
    for (int64_t i = 0; i < count; ++i) {
        free(arr[i].name);
        free(arr[i].params);
    }
    free(arr);
}
}