#include <cstdint>

class moo {
public:
    static int64_t absolute(int64_t x) {
        if (x == 0) return 0;
        return x < (0) ? -x : x;
    }

    static int64_t min(int64_t a, int64_t b) {
        return a < b ? a : b;
    }

    static int64_t max(int64_t a, int64_t b) {
        return a > b ? a : b;
    }

    static int64_t gcd(int64_t a, int64_t b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static int64_t lcm(int64_t n, int64_t k) {
        if (n == 0 || k == 0) return 0;
        int64_t g = gcd(n, k);
        return absolute(n / g * k);
    }
};

// @formatter:off

extern "C" {
    __declspec(dllexport) int64_t absolute(int64_t x) { return moo::absolute(x); }
    __declspec(dllexport) int64_t min(int64_t a, int64_t b) { return moo::min(a, b); }
    __declspec(dllexport) int64_t max(int64_t a, int64_t b) { return moo::max(a, b); }

    __declspec(dllexport) int64_t gcd(int64_t a, int64_t b) { return moo::gcd(a, b); }
    __declspec(dllexport) int64_t lcm(int64_t n, int64_t k) { return moo::lcm(n, k); }
}
// @formatter:on