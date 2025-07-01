#pragma once

#include <cstdint>

class moo {
public:
    static int64_t absolute(int64_t x);
    static int64_t min(int64_t a, int64_t b);
    static int64_t max(int64_t a, int64_t b);
    static int64_t gcd(int64_t a, int64_t b);
    static int64_t lcm(int64_t a, int64_t b);
    static int64_t factorial(int n);
    static int64_t binom(int64_t n, int64_t k);
};