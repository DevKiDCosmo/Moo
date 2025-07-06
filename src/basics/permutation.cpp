#include <cstdint>
#include <limits>
#include <algorithm>
#include "../moo.hpp"
#include "../export.h"


void swap(int64_t& a, int64_t& b) {
    int64_t t = a;
    a         = b;
    b         = t;
}

void permute(int64_t* arr, int l, int r, int64_t* out, int64_t& index) {
    if (l == r) {
        for (int i = 0; i < r; ++i) out[index * r + i] = arr[i];
        ++index;
        return;
    }

    for (int i = l; i < r; ++i) {
        swap(arr[l], arr[i]);
        permute(arr, l + 1, r, out, index);
        swap(arr[l], arr[i]);
    }
}


int64_t* moo::factable(int n) {
    if (n < 0 || n > 20) return nullptr;

    auto* result = static_cast<int64_t*>(malloc(sizeof(int64_t) * (n + 1)));
    if (!result) return nullptr;

    result[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (result[i - 1] > std::numeric_limits<int64_t>::max() / i) {
            free(result);
            return nullptr;
        }
        result[i] = result[i - 1] * i;
    }

    return result;
}

void moo::clearptr(const int64_t* ptr) {
    free(const_cast<int64_t*>(ptr));
}

int64_t* moo::genPerm(int n) {
    if (n < 0 || n > 12) return nullptr; // 13! > 6 × 10^9 -> RAM Warnung
    int64_t total = 1;
    for (int i = 2; i <= n; ++i) total *= i;

    auto* result = static_cast<int64_t*>(malloc(sizeof(int64_t) * total * n));
    if (!result) return nullptr;

    auto* base = static_cast<int64_t*>(malloc(sizeof(int64_t) * n));
    if (!base) {
        free(result);
        return nullptr;
    }

    for (int i = 0; i < n; ++i) base[i] = i + 1;

    int64_t index = 0;
    permute(base, 0, n, result, index);
    free(base);
    return result;
}

void moo::freeptr(int64_t* ptr) {
    free(ptr);
}

int64_t moo::permutation(int n, int k) {
    if (n < 0 || k < 0 || k > n || n > 20) return -1;

    int64_t fact = 1;
    for (int i = n - k + 1; i <= n; ++i) {
        if (fact > std::numeric_limits<int64_t>::max() / i) return -1;
        fact *= i;
    }

    return fact;
}

int64_t moo::combination(int n, int k) {
    if (n < 0 || k < 0 || k > n || n > 20) return -1;
    return int64_t(fac(n) / (fac(k) * fac(n - k)));
}

extern "C" {
MOOLIB_API int64_t* factable(int n) {
    return moo::factable(n);
}

MOOLIB_API void clearptr(const int64_t* ptr) {
    moo::clearptr(ptr);
}

MOOLIB_API int64_t* genPerm(int n) {
    return moo::genPerm(n);
}

MOOLIB_API void freeptr(int64_t* ptr) {
    moo::freeptr(ptr);
}

MOOLIB_API void permutation(int n, int k) {
    moo::permutation(n, k);
}

MOOLIB_API void combination(int n, int k) {
    moo::combination(n, k);
}
}