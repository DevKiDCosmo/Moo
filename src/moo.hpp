#pragma once

#include <cstdint>
#include <string>
#include <variant>

class moo {
public:
    static double  absolute(double x);
    static double  min(double a, double b);
    static double  max(double a, double b);
    static int64_t gcd(int64_t a, int64_t b);
    static int64_t lcm(int64_t a, int64_t b);
    static int64_t fac(int n);
    static int64_t binom(int64_t n, int64_t k);
    static double  flmod(double a, double b);
    static int64_t mod(int64_t a, int64_t b);

    static double  floor(double x);
    static double  ceil(double x);
    static int64_t idiv(double n, double k);

    static int64_t* factable(int n);
    static void     clearptr(const int64_t* ptr);
    static int64_t* genPerm(int n);
    static void     freeptr(int64_t* ptr);
    static int64_t  permutation(int n, int k);
    static int64_t  combination(int n, int k);
    static double   pow(double base, int64_t exp);
    static double   fpow(double base, double exp);

    static double ln(double x);
    static double log(double x, double base = 10.0);
    static double exp(double x);
};