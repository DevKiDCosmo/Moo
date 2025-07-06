#pragma once

#if defined(_WIN32)
  #ifdef MOOLIB_EXPORTS
    #define MOOLIB_API __declspec(dllexport)
  #else
    #define MOOLIB_API __declspec(dllexport)
  #endif
#elif defined(__GNUC__) && __GNUC__ >= 4
  #define MOOLIB_API __attribute__((visibility("default")))
#else
  #define MOOLIB_API
#endif
