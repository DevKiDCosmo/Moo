// src/numset/numsets.hpp
#pragma once

#include <variant>
#include <complex>
#include <stdexcept>

#ifdef MOONUMS_EXPORTS
#define MOONUMS_API __declspec(dllexport)
#else
#define MOONUMS_API __declspec(dllimport)
#endif

class MOONUMS_API moonums {
public:
    struct MOONUMS_API rational {
        long long numerator;
        long long denominator;

        rational(long long num = 0, long long denom = 1) : numerator(num), denominator(denom) {
            if (denominator == 0) {
                throw std::invalid_argument("Denominator cannot be 0");
            }
        }
    };

    using generic_number = std::variant<int, long, double, long double, std::complex<double>, rational>;

    struct MOONUMS_API number {
        std::variant<int, double, long double, std::complex<double>, rational> value;
    };

    struct MOONUMS_API naturalNumber {
        int value;

        naturalNumber(int val) : value(val) {
            if (val < 0) {
                throw std::invalid_argument("Natural Numbers must >= 0");
            }
        }
    };

    // TODO: Using pointer to access structs for C compatibility and for dll export.
};