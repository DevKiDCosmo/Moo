#include <cstdint>

class moo {
public:
    static double absolute(double x) {
        if (x == 0) return 0;
        return x < (0) ? -x : x;
    }

    static double min(double a, double b) {
        return a < b ? a : b;
    }

    static double max(double a, double b) {
        return a > b ? a : b;
    }

    static double floor(double x) {
        return x < 0 ? static_cast<double>(static_cast<int64_t>(x) - 1) : static_cast<double>(static_cast<int64_t>(x));
    }

    static double ceil(double x) {
        return x < 0 ? static_cast<double>(static_cast<int64_t>(x)) : static_cast<double>(static_cast<int64_t>(x) + 1);
    }

    static double flmod(double a, double b) {
        if (b == 0) return 0;
        return a - b * floor(a / b);
    }

    static int64_t mod(int64_t a, int64_t b) {
        if (b == 0) return 0;
        return a % b < 0 ? a % b + b : a % b;
    }

    static int64_t gcd(int64_t a, int64_t b) {
        return b == 0 ? a : gcd(b, static_cast<int64_t>(mod(a, b)));
    }

    static int64_t lcm(int64_t n, int64_t k) {
        if (n == 0 || k == 0) return 0;
        double g = gcd(n, k);
        return static_cast<int64_t>(absolute(n / g * k));
    }
};

// @formatter:off

extern "C" {
    __declspec(dllexport) double absolute(double x) { return moo::absolute(x); }
    __declspec(dllexport) double min(double a, double b) { return moo::min(a, b); }
    __declspec(dllexport) double max(double a, double b) { return moo::max(a, b); }

    __declspec(dllexport) int64_t gcd(int64_t a, int64_t b) { return moo::gcd(a, b); }
    __declspec(dllexport) int64_t lcm(int64_t n, int64_t k) { return moo::lcm(n, k); }
    __declspec(dllexport) double flmod(double a, double b) { return moo::flmod(a, b); }
    __declspec(dllexport) double mod(int64_t a, int64_t b) { return moo::mod(a, b); }

    __declspec(dllexport) double floor(double x) { return moo::floor(x); }
    __declspec(dllexport) double ceil(double x) { return moo::ceil(x); }
}
// @formatter:on