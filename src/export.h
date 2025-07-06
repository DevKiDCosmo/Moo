#pragma once

#if defined(_WIN32)
  #ifdef MOOLIB_EXPORTS
    #define MOOLIB_API __declspec(dllexport)
  #else
    #define MOOLIB_API __declspec(dllimport)
  #endif
#else
  #define MOOLIB_API __attribute__((visibility("default")))
#endif