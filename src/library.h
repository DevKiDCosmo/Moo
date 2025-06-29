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
    // Basisfunktionen
    THEMATHLIBLIBRARY_API int    _addInteration(int n, int k);
    THEMATHLIBLIBRARY_API double _pow(double base, int exponent);
    THEMATHLIBLIBRARY_API double _sqrt(float number);
    THEMATHLIBLIBRARY_API double _invsqrt(float number);
    THEMATHLIBLIBRARY_API double _nroot(double number, int n, int iterations);

    // Optional: Überladungen für _abs (falls wirklich benötigt)
    /*
    THEMATHLIBLIBRARY_API int    _abs(int n);
    THEMATHLIBLIBRARY_API float  _absf(float n);
    THEMATHLIBLIBRARY_API double _absd(double n);
    */
}

#endif // THEMATHLIB_LIBRARY_H
