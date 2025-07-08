#pragma once
#include <cstdint>
#include <vector>

#include "moo.hpp"
#include "export.h"

#ifndef MOO_LIBRARY_H
#define MOO_LIBRARY_H

extern "C" {
MOOLIB_API int64_t fac(int n);
MOOLIB_API int64_t binom(int64_t n, int64_t k);
MOOLIB_API int64_t gcd(int64_t n, int64_t k);
MOOLIB_API int64_t lcm(int64_t n, int64_t k);

MOOLIB_API double  absolute(double x);
MOOLIB_API double  min(double a, double b);
MOOLIB_API double  max(double a, double b);
MOOLIB_API int64_t mod(int64_t a, int64_t b);
MOOLIB_API double  flmod(double a, double b);

MOOLIB_API double dfloor(double x); // double floor - to prevent conflicts with std::floor etc.
MOOLIB_API double dceil(double x);  // Both in the std - conflict by release buildinf - no conflict by debug buildinf

MOOLIB_API int64_t idiv(double n, double k);

MOOLIB_API int64_t* factable(int n);
MOOLIB_API void     clearptr(const int64_t* ptr);

MOOLIB_API int64_t* genPerm(int n); // n! Permutationen mit Länge n
MOOLIB_API void     freeptr(int64_t* ptr);
MOOLIB_API int64_t  permutation(int n, int k);
MOOLIB_API int64_t  combination(int n, int k);
MOOLIB_API double   dpow(double base, int64_t exp);
MOOLIB_API double   fpow(double base, double exp);

MOOLIB_API double dexp(double x);
MOOLIB_API double dlog(double x, double base);
MOOLIB_API double ln(double x);
MOOLIB_API double dsqrt(double x);
MOOLIB_API double dksqrt(double x, double k);
MOOLIB_API double rounding(double x);
MOOLIB_API double roundk(double x, int k);

// advance/interval.cpp
MOOLIB_API nullptr_t i();
typedef int64_t (*   interval_func_t)(const int64_t* args, int64_t argCount);
MOOLIB_API int64_t*  interval_c(int64_t        start, int64_t  end, int64_t   step, int64_t argCount,
                               interval_func_t func, int64_t** vars, int64_t* out_count);

// utility/queue.cpp
struct func_call_c {
    int64_t  id;
    char*    name;
    int64_t* params;
    int64_t  param_count;
};

MOOLIB_API double       executefunc(const char* name, const int64_t* params, int64_t param_count);
MOOLIB_API void         executedfunc(int64_t id, double result);
MOOLIB_API func_call_c* get_all_func_calls(int64_t* out_count);
MOOLIB_API void         free_func_calls(func_call_c* arr, int64_t count);
}

#endif // MOO_LIBRARY_H