#pragma once

#include <cstdint>
#include <functional>
#include <string>
#include <variant>
#include <vector>
#include <optional>
#include <condition_variable>
#include <mutex>

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
    static double   round(double x);
    static double   roundk(double x, int k);
    static double   sqrt(double x);
    static double   ksqrt(double x, double k);

    static double ln(double x);
    static double log(double x, double base = 10.0);
    static double exp(double x);

    static double sine(double x);
    static double cosine(double x);
    static double tangent(double x);
    static double normalizer(double x);
    static double arcsine(double x);
    static double arccosine(double x);
    static double arctangent(double x);
    static double cosinehyperbolic(double x);
    static double tangenthyperbolic(double x);
    static double arcsinehyperbolic(double x);
    static double arccosinehyperbolic(double x);
    static double arctangenthyperbolic(double x);
    static double sinehyperbolic(double x);

    static double* primefac(double x);
    static double  pi();
};