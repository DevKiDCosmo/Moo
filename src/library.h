#ifndef MOO_LIBRARY_H
#define MOO_LIBRARY_H

// MOO Library Header
#include "numset/numsets.hpp"

#ifdef _WIN32
#ifdef MOOLIB_EXPORTS
    #define MOOLIB_API __declspec(dllexport)
#else
#define MOOLIB_API __declspec(dllimport)
#endif
#else
  #define MOOLIB_API
#endif

#include <type_traits>
#include <cstring>

extern "C" {
MOOLIB_API int fac(int n); // factorial
MOOLIB_API int binom(int n, int k); // binomial coefficient
MOOLIB_API int gcd(int n, int k);
MOOLIB_API int lcm(int n, int k);

// int-Versionen
MOOLIB_API int abs_(int x);
MOOLIB_API int min(int a, int b);
MOOLIB_API int max(int a, int b);

// float-Versionen
MOOLIB_API float abs_float(float x);
MOOLIB_API float min_float(float a, float b);
MOOLIB_API float max_float(float a, float b);

// double-Versionen
MOOLIB_API double abs_double(double x);
MOOLIB_API double min_double(double a, double b);
MOOLIB_API double max_double(double a, double b);
}

#endif // MOO_LIBRARY_H