#include <cstdint>
#include "../moo.hpp"

int64_t moo::fac(int n) {
    if (n <= 1) return 1;
    return n * fac(n - 1);
}


// @formatter:off
extern "C" {
    __declspec(dllexport) int64_t fac(const int n)
    {
        return moo::fac(n);
    }
}
// @formatter:on