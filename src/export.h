#pragma once
#include <iostream>

#if defined(_WIN32)
#ifdef MOOLIB_EXPORTS
    #define MOOLIB_API __declspec(dllexport)
#else
#define MOOLIB_API __declspec(dllexport)
#endif
#else
  #define MOOLIB_API __attribute__((visibility("default")))
std::cout << "Building for non-Windows platform, using default visibility." << std::endl;
#endif