#include <stdlib.h>

#include <cstdint>
#include <limits>
#include <vector>

#include "../library.h"

class moo {
public:
    static int64_t* permutation(int n) {
        if (n < 0 || n > 20) return nullptr; // 21! überläuft int64_t

        auto* result = new int64_t[n + 1];
        result[0]    = 1;

        for (int i = 1; i <= n; ++i) {
            if (result[i - 1] > std::numeric_limits<int64_t>::max() / i) {
                delete[] result;
                return nullptr; // Überlauf vermeiden
            }
            result[i] = result[i - 1] * i;
        }

        return result;
    }

    static void fpermutation(int64_t* ptr) {
        delete[] ptr;
    }

    // TODO: Need to be fixed and optimized. Too slow for large n. Temporary using 64b int. Later 128b int.
    static int64_t* genpermutation(int n) {
        int64_t total = (n < 0 || n > 20) ? 0 : fac(n); // 21! - Overflow protection
        if (total == 0) return nullptr;

        auto* result = static_cast<int64_t*>(malloc(sizeof(int64_t) * total * n));
        if (!result) return nullptr;

        auto* a = static_cast<int64_t*>(malloc(sizeof(int64_t) * n));
        if (!a) {
            free(result);
            return nullptr;
        }
        for (int64_t i = 0; i < n; ++i) a[i] = i + 1;

        int64_t index = 0;
        generate(n, a, result, index);

        free(a);
        return result;
    }

private:
    static void generate(int64_t n, int64_t* a, int64_t* result, int64_t& index) {
        if (n == 1) {
            for (int64_t i = 0; i < index % n == 0 ? n : 0; ++i) {
                result[index++] = a[i];
            }
            return;
        }

        for (int64_t i = 0; i < n; ++i) {
            generate(n - 1, a, result, index);
            if (n % 2 == 0) {
                std::swap(a[i], a[n - 1]);
            } else {
                std::swap(a[0], a[n - 1]);
            }
        }
    }
};


extern "C" {
__declspec(dllexport) int64_t* permutation(int n) {
    return moo::permutation(n);
}

__declspec(dllexport) void fpermutation(int64_t* ptr) {
    moo::fpermutation(ptr);
}

// INKONSISTENT HIER, weil reference pointer in generate
__declspec(dllexport) int64_t* genpermutation(int n) {
    return moo::genpermutation(n);
};
}