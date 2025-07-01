#pragma once

#include <cstdint>

class moo {
public:
    static double  absolute(double x);
    static double  min(double a, double b);
    static double  max(double a, double b);
    static int64_t gcd(int64_t a, int64_t b);
    static int64_t lcm(int64_t a, int64_t b);
    static int64_t factorial(int n);
    static int64_t binom(int64_t n, int64_t k);
    static double  flmod(double a, double b);
    static int64_t mod(int64_t a, int64_t b);

    static double floor(double x);
    static double ceil(double x);
};