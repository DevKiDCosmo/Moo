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
  THEMATHLIBLIBRARY_API int factorial(int n);
  THEMATHLIBLIBRARY_API int binomial_coefficient(int n, int k);
}

#endif // THEMATHLIB_LIBRARY_H
