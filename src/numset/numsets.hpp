#pragma once

#include <variant>
#include <complex>

class moonums {
public:
    struct rational {
        long long numerator;
        long long denominator;

        rational(long long num = 0, long long denom = 1) : numerator(num), denominator(denom) {
            if (denominator == 0) {
                throw std::invalid_argument("Numerator cannot be 0");
            }
        }
    };

    using generic_number = std::variant<int, long, double, long double, std::complex<double>, rational>;

    struct number {
        // can also be uninum or moo_number
        std::variant<int, double, long double, std::complex<double>, rational> value;
    };

    struct natural_number {
        int value;

        natural_number(int val) : value(val) {
            if (val < 0) {
                throw std::invalid_argument("Natural Numbers must >= 0");
            }
        }
    };

    natural_number natural_number(int val) { return natural_number(val); }
};