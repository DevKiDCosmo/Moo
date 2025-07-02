#pragma once
#include <cstdint>
#include <vector>

#ifndef MOO_LIBRARY_H
#define MOO_LIBRARY_H

#ifdef _WIN32
#ifdef MOOLIB_EXPORTS
    #define MOOLIB_API __declspec(dllexport)
#else
#define MOOLIB_API __declspec(dllimport)
#endif
#else
  #define MOOLIB_API
#endif


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
MOOLIB_API double dceil(double x);  // Both in the std - conflict by release build - no conflict by debug build

MOOLIB_API int64_t idiv(double n, double k);

MOOLIB_API int64_t* factable(int n); // n+1 Werte
MOOLIB_API void     clearptr(const int64_t* ptr);

MOOLIB_API int64_t* genPerm(int n); // n! Permutationen mit Länge n
MOOLIB_API void     freePerm(int64_t* ptr);
MOOLIB_API int64_t  permutation(int n, int k);
}

#endif // MOO_LIBRARY_H