#pragma once
#include <cstdint>
#include <vector>

#include "moo.hpp"

#ifndef MOO_LIBRARY_H
#define MOO_LIBRARY_H

#ifdef _WIN32
  #ifdef MOOLIB_EXPORTS
    #define MOOLIB_API __declspec(dllexport)
  #else
    #define MOOLIB_API __declspec(dllimport)
  #endif
#elif defined(__unix__) || defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__sun) || defined(__CYGWIN__)
  // Unix-based systems (Linux, macOS, BSD variants, Solaris, Cygwin)
  #if defined(__GNUC__) && __GNUC__ >= 4
    #define MOOLIB_API __attribute__((visibility("default")))
  #else
    #define MOOLIB_API
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
MOOLIB_API double dceil(double x);  // Both in the std - conflict by release buildinf - no conflict by debug buildinf

MOOLIB_API int64_t idiv(double n, double k);

MOOLIB_API int64_t* factable(int n); // n+1 Werte
MOOLIB_API void     clearptr(const int64_t* ptr);

MOOLIB_API int64_t* genPerm(int n); // n! Permutationen mit Länge n
MOOLIB_API void     freeptr(int64_t* ptr);
MOOLIB_API int64_t  permutation(int n, int k);
MOOLIB_API int64_t  combination(int n, int k);
}

#endif // MOO_LIBRARY_H