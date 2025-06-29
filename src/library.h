#ifndef THEMATHLIB_LIBRARY_H
#define THEMATHLIB_LIBRARY_H

#ifdef _WIN32
#ifdef THEMATHLIBLIBRARY_EXPORTS
    #define THEMATHLIBLIBRARY_API __declspec(dllexport)
#else
#define THEMATHLIBLIBRARY_API __declspec(dllimport)
#endif
#else
  #define THEMATHLIBLIBRARY_API
#endif

#include <type_traits>
#include <cstring>

extern "C" {
    THEMATHLIBLIBRARY_API int fac(int n);                       // factorial
    THEMATHLIBLIBRARY_API int binom(int n, int k);              // binomial coefficient
    THEMATHLIBLIBRARY_API int gcd(int n, int k);
    THEMATHLIBLIBRARY_API int lcm(int n, int k);

    // int-Versionen
    THEMATHLIBLIBRARY_API int abs(int x);
    THEMATHLIBLIBRARY_API int min(int a, int b);
    THEMATHLIBLIBRARY_API int max(int a, int b);

    // float-Versionen
    THEMATHLIBLIBRARY_API float abs_float(float x);
    THEMATHLIBLIBRARY_API float min_float(float a, float b);
    THEMATHLIBLIBRARY_API float max_float(float a, float b);

    // double-Versionen
    THEMATHLIBLIBRARY_API double abs_double(double x);
    THEMATHLIBLIBRARY_API double min_double(double a, double b);
    THEMATHLIBLIBRARY_API double max_double(double a, double b);
}

#endif // THEMATHLIB_LIBRARY_H
