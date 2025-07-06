#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#define LOAD_LIBRARY(path) LoadLibrary(path)
#define GET_FUNCTION(lib, name) GetProcAddress(lib, name)
#define CLOSE_LIBRARY(lib) FreeLibrary(lib)
typedef HMODULE LibHandle;
#else
#include <dlfcn.h>
#define LOAD_LIBRARY(path) dlopen(path, RTLD_LAZY)
#define GET_FUNCTION(lib, name) dlsym(lib, name)
#define CLOSE_LIBRARY(lib) dlclose(lib)
typedef void* LibHandle;
#endif

// Function pointer types
typedef int64_t (*fac_func)(int);
typedef int64_t (*binom_func)(int64_t, int64_t);
typedef double (*absolute_func)(double);
typedef int64_t (*gcd_func)(int64_t, int64_t);

int main() {
    // Determine library name based on platform
    std::string lib_name;
#ifdef _WIN32
    lib_name = "moo.dll";  // or MooMeson.dll for release
#elif __APPLE__
    lib_name = "./libMoo.dylib";  // or ./libMooMeson.dylib for release
#else
    lib_name = "./libMoo.so";  // or ./libMooMeson.so for release
#endif

    // Load the library
    LibHandle lib = LOAD_LIBRARY(lib_name.c_str());
    if (!lib) {
        std::cerr << "Failed to load library: " << lib_name << std::endl;
#ifndef _WIN32
        std::cerr << "Error: " << dlerror() << std::endl;
#endif
        return 1;
    }

    // Get function pointers
    fac_func fac = (fac_func)GET_FUNCTION(lib, "fac");
    binom_func binom = (binom_func)GET_FUNCTION(lib, "binom");
    absolute_func absolute = (absolute_func)GET_FUNCTION(lib, "absolute");
    gcd_func gcd = (gcd_func)GET_FUNCTION(lib, "gcd");

    if (!fac || !binom || !absolute || !gcd) {
        std::cerr << "Failed to load one or more functions" << std::endl;
        CLOSE_LIBRARY(lib);
        return 1;
    }

    // Demonstrate library functionality
    std::cout << "=== Moo Mathematical Library Demo ===" << std::endl;
    std::cout << "Platform: ";
#ifdef _WIN32
    std::cout << "Windows" << std::endl;
#elif __APPLE__
    std::cout << "macOS" << std::endl;
#elif __linux__
    std::cout << "Linux" << std::endl;
#elif __FreeBSD__
    std::cout << "FreeBSD" << std::endl;
#elif __OpenBSD__
    std::cout << "OpenBSD" << std::endl;
#elif __NetBSD__
    std::cout << "NetBSD" << std::endl;
#elif __sun
    std::cout << "Solaris" << std::endl;
#else
    std::cout << "Unix-like" << std::endl;
#endif

    std::cout << std::endl;

    // Test mathematical functions
    std::cout << "Mathematical Functions:" << std::endl;
    std::cout << "  fac(5) = " << fac(5) << std::endl;
    std::cout << "  fac(10) = " << fac(10) << std::endl;
    std::cout << "  binom(10, 3) = " << binom(10, 3) << std::endl;
    std::cout << "  binom(5, 2) = " << binom(5, 2) << std::endl;
    std::cout << "  absolute(-42.5) = " << absolute(-42.5) << std::endl;
    std::cout << "  absolute(17.8) = " << absolute(17.8) << std::endl;
    std::cout << "  gcd(48, 18) = " << gcd(48, 18) << std::endl;
    std::cout << "  gcd(100, 25) = " << gcd(100, 25) << std::endl;

    std::cout << std::endl << "All functions executed successfully!" << std::endl;

    // Clean up
    CLOSE_LIBRARY(lib);
    return 0;
}