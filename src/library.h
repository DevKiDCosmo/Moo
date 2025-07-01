#include <cstdint>

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
MOOLIB_API int64_t binom(int64_t n, int64_t k); // Binomialkoeffizient
MOOLIB_API int64_t gcd(int64_t n, int64_t k);
MOOLIB_API int64_t lcm(int64_t n, int64_t k);

MOOLIB_API double absolute(double x);
MOOLIB_API double min(double a, double b);
MOOLIB_API double max(double a, double b);
}

#endif // MOO_LIBRARY_H