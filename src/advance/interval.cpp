#include "../moo.hpp"
#include "../export.h"
#include <iostream>
#include <functional>

nullptr_t moo::i() {
    return nullptr;
}

std::vector<int64_t> moo::interval(
    int64_t                                             start, int64_t end, int64_t step, int64_t argCount,
    std::function<int64_t(const std::vector<int64_t>&)> func, const std::vector<int64_t*>& vars
    ) {
    if (step <= 0 || start > end) {
        throw std::invalid_argument("Invalid interval arguments.");
    }
    if (!func) {
        throw std::invalid_argument("Function cannot be empty.");
    }
    if (vars.empty() || vars.size() != static_cast<size_t>(argCount)) {
        throw std::invalid_argument("Wrong size of vars.");
    }

    // Finde die Position der Intervall-Variable (nullptr)
    int64_t iterationIndex = -1;
    for (int64_t i = 0; i < argCount; ++i) {
        if (vars[i] == nullptr) {
            iterationIndex = i;
            break;
        }
    }
    if (iterationIndex == -1) {
        throw std::invalid_argument("Interval fixpoint nullptr not found in vars.");
    }

    std::vector<int64_t> result;
    std::vector<int64_t> varValues(argCount);

    // Initialisiere bekannte Variablen
    for (int64_t i = 0; i < argCount; ++i) {
        if (vars[i] != moo::i()) {
            varValues[i] = *vars[i];
        }
    }

    for (int64_t i = start; i <= end; i += step) {
        varValues[iterationIndex] = i;
        result.push_back(func(varValues));
    }
    return result;
}


extern "C" {
MOOLIB_API nullptr_t i() {
    return moo::i();
}

MOOLIB_API int64_t* interval_c(
    int64_t   start, int64_t end, int64_t step, int64_t argCount,
    char*     func,
    int64_t** vars,
    int64_t*  out_count
    ) {
    if (!func || !vars || !out_count) return nullptr;

    std::vector<int64_t> result;
    try {
        if (step <= 0 || start > end) {
            throw std::invalid_argument("Invalid interval arguments.");
        }
        for (int64_t i = 0; i < argCount; ++i) {
            if (vars[i] == nullptr) {
                // mindestens ein nullptr gefunden, also ok
                break;
            }
            if (i == argCount - 1) {
                throw std::invalid_argument("Wrong size of vars or no nullptr found.");
            }
        }

        // Finde die Position der Intervall-Variable (nullptr)
        int64_t iterationIndex = -1;
        for (int64_t i = 0; i < argCount; ++i) {
            if (vars[i] == nullptr) {
                iterationIndex = i;
                break;
            }
        }
        if (iterationIndex == -1) {
            throw std::invalid_argument("Interval fixpoint nullptr not found in vars.");
        }

        std::vector<double>  result;
        std::vector<int64_t> varValues(argCount);

        // Initialisiere bekannte Variablen
        for (int64_t i = 0; i < argCount; ++i) {
            if (vars[i] != moo::i()) {
                varValues[i] = *vars[i];
            }
        }

        for (int64_t i = start; i <= end; i += step) {
            varValues[iterationIndex] = i;
            result.push_back(moo::executefunc(func, varValues));
        }
    } catch (...) {
        *out_count = 0;
        return moo::i();
    }

    // Ergebnis-Array für C allokieren
    *out_count = static_cast<int64_t>(result.size());
    auto* out  = static_cast<int64_t*>(malloc(result.size() * sizeof(int64_t)));
    if (!out) {
        *out_count = 0;
        return nullptr;
    }
    std::copy(result.begin(), result.end(), out);
    return out;
}
}