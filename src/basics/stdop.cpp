#include <cstdint>
#include "../moo.hpp"

double moo::absolute(double x) {
    if (x == 0) return 0;
    return x < 0 ? -x : x;
}

double moo::min(double a, double b) {
    return a < b ? a : b;
}

double moo::max(double a, double b) {
    return a > b ? a : b;
}

double moo::floor(double x) {
    return x < 0 ? static_cast<double>(static_cast<int64_t>(x) - 1) : static_cast<double>(static_cast<int64_t>(x));
}

double moo::ceil(double x) {
    return x < 0 ? static_cast<double>(static_cast<int64_t>(x)) : static_cast<double>(static_cast<int64_t>(x) + 1);
}

double moo::flmod(double a, double b) {
    if (b == 0) return 0;
    return a - b * floor(a / b);
}

int64_t moo::mod(int64_t a, int64_t b) {
    if (b == 0) return 0;
    return a % b < 0 ? a % b + b : a % b;
}

int64_t moo::gcd(int64_t a, int64_t b) {
    return b == 0 ? a : gcd(b, mod(a, b));
}

int64_t moo::lcm(int64_t n, int64_t k) {
    if (n == 0 || k == 0) return 0;
    auto g = gcd(n, k);
    return static_cast<int64_t>(absolute(n / g * k));
}

int64_t moo::idiv(double n, double k) {
    return static_cast<int64_t>(floor(n / k));
}


// @formatter:off

extern "C" {
    __declspec(dllexport) double absolute(double x) { return moo::absolute(x); }
    __declspec(dllexport) double min(double a, double b) { return moo::min(a, b); }
    __declspec(dllexport) double max(double a, double b) { return moo::max(a, b); }

    __declspec(dllexport) int64_t gcd(int64_t a, int64_t b) { return moo::gcd(a, b); }
    __declspec(dllexport) int64_t lcm(int64_t n, int64_t k) { return moo::lcm(n, k); }
    __declspec(dllexport) double flmod(double a, double b) { return moo::flmod(a, b); }
    __declspec(dllexport) int64_t mod(int64_t a, int64_t b) { return moo::mod(a, b); }

    __declspec(dllexport) double dfloor(double x) { return moo::floor(x); }
    __declspec(dllexport) double dceil(double x) { return moo::ceil(x); }

    __declspec(dllexport) int64_t idiv(double a, double b) { return moo::idiv(a,b); }
}
// @formatter:on