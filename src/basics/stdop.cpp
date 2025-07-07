#include <cstdint>
#include "../moo.hpp"
#include "../export.h"
#include <cmath>

double moo::absolute(double x) {
    if (x == 0) return 0;
    return x < 0 ? -x : x;
}

double moo::min(double a, double b) {
    return a < b ? a : b;
}

double moo::max(double a, double b) {
    return a > b ? a : b;
}

double moo::floor(double x) {
    return x < 0 ? static_cast<double>(static_cast<int64_t>(x) - 1) : static_cast<double>(static_cast<int64_t>(x));
}

double moo::ceil(double x) {
    return x < 0 ? static_cast<double>(static_cast<int64_t>(x)) : static_cast<double>(static_cast<int64_t>(x) + 1);
}

double moo::flmod(double a, double b) {
    if (b == 0) return 0;
    return a - b * floor(a / b);
}

int64_t moo::mod(int64_t a, int64_t b) {
    if (b == 0) return 0;
    return a % b < 0 ? a % b + b : a % b;
}

int64_t moo::gcd(int64_t a, int64_t b) {
    return b == 0 ? a : gcd(b, mod(a, b));
}

int64_t moo::lcm(int64_t n, int64_t k) {
    if (n == 0 || k == 0) return 0;
    auto g = gcd(n, k);
    return static_cast<int64_t>(absolute(n / g * k));
}

int64_t moo::idiv(double n, double k) {
    return static_cast<int64_t>(floor(n / k));
}

double moo::pow(double base, int64_t exp) {
    if (base == 0 && exp <= 0) {
        return 1 / pow(base, -exp);
    }
    if (exp == 0) return 1; // Jede Zahl hoch 0 ist 1

    bool    neg_exp = exp < 0;
    int64_t abs_exp = neg_exp ? -exp : exp;
    double  result  = 1.0;
    double  b       = base;

    // Exponentiation by squaring
    while (abs_exp > 0) {
        if (abs_exp % 2 == 1) result *= b;
        b *= b;
        abs_exp /= 2;
    }

    return neg_exp ? 1.0 / result : result;
}

double moo::exp(double x) {
    if (x == 0) return 1; // e^0 = 1
    if (x < -709.782712893384) return 0;
#if defined(_WIN32)
    if (x > 709.782712893384) return std::numeric_limits<double>::infinity();
#else
    if (x > 709.782712893384) return 1.0 / 0.0;
#endif

    double  sum  = 1.0;
    double  term = 1.0;
    int64_t n    = 1;

    while (term > 1e-15 || term < -1e-15) {
        term *= x / n;
        sum += term;
        n++;
    }

    return sum;
}

double moo::log(double x, double base) {
    if (x <= 0 || base <= 1) return 0;               // log(x) ist undefiniert für x <= 0 oder base <= 1
    if (base == 10) return moo::ln(x) / moo::ln(10); // log_10(x)
    if (base == 2) return moo::ln(x) / moo::ln(2);   // log_2(x)
    return moo::ln(x) / moo::ln(base);               // log_base(x)
}

double moo::ln(double x) {
    if (x <= 0) return 0;
    if (x == 1) return 0; // ln(1) = 0

    double sum          = 0.0;
    double term         = (x - 1) / (x + 1);
    double term_squared = term * term;
    double n            = 1.0;

    while (term > 1e-15 || term < -1e-15) {
        sum += term / n;
        term *= term_squared;
        n += 2.0;
    }

    return 2.0 * sum;
}

double moo::fpow(double base, double exp) {
    if (base == 0 && exp <= 0) {
        return 1 / fpow(base, -exp);
    }
    if (exp == 0) return 1; // Jede Zahl hoch 0 ist 1

    bool   neg_exp = exp < 0;
    double abs_exp = neg_exp ? -exp : exp;
    double result  = 1.0;
    double b       = base;

    if (static_cast<int64_t>(abs_exp) == abs_exp) {
        return moo::pow(base, static_cast<int64_t>(abs_exp));
    }

    // exp(exp * ln(base))
    if (base < 0) return 0;
    return moo::exp(exp * moo::ln(base));
}

double moo::round(double x) {
    if (x < 0) {
        return static_cast<double>(static_cast<int64_t>(x - 0.5));
    } else {
        return static_cast<double>(static_cast<int64_t>(x + 0.5));
    }
}

double moo::roundk(double x, int k) {
    double factor = moo::pow(10.0, -k);
    return moo::round(x * factor) / factor;
}


double moo::sqrt(double x) {
    if (x < 0) return 0;
    if (x == 0) return 0;

    double low  = 0;
    double high = x < 1 ? 1 : x; // für x ∈ [0, 1)
    double mid;

    while (high - low > 1e-15) {
        mid = (low + high) / 2.0;
        if (mid * mid < x) {
            low = mid;
        } else {
            high = mid;
        }
    }

    double approx = (low + high) / 2.0;

    double rounded = moo::round(approx);
    if (moo::absolute(approx - rounded) < 1e-10) {
        return rounded;
    }

    return approx;
}

double moo::ksqrt(double x, double k) {
    if (x < 0 && static_cast<int64_t>(k) % 2 == 0) return 0;

    double v = exp(1 / k * ln(x));

    double approx = v;

    double rounded = moo::round(approx);
    if (moo::absolute(approx - rounded) < 1e-10) {
        return rounded;
    }

    return v;
}

// @formatter:off

extern "C" {
    MOOLIB_API double absolute(double x) { return moo::absolute(x); }
    MOOLIB_API double min(double a, double b) { return moo::min(a, b); }
    MOOLIB_API double max(double a, double b) { return moo::max(a, b); }

    MOOLIB_API int64_t gcd(int64_t a, int64_t b) { return moo::gcd(a, b); }
    MOOLIB_API int64_t lcm(int64_t n, int64_t k) { return moo::lcm(n, k); }
    MOOLIB_API double flmod(double a, double b) { return moo::flmod(a, b); }
    MOOLIB_API int64_t mod(int64_t a, int64_t b) { return moo::mod(a, b); }

    MOOLIB_API double dfloor(double x) { return moo::floor(x); }
    MOOLIB_API double dceil(double x) { return moo::ceil(x); }

    MOOLIB_API int64_t idiv(double a, double b) { return moo::idiv(a,b); }
    MOOLIB_API double dpow(double base, int64_t exp) { return moo::pow(base, exp); }
    MOOLIB_API double fpow(double base, double exp) { return moo::fpow(base, exp); }

    MOOLIB_API double dexp(double x) { return moo::exp(x); }
    MOOLIB_API double dlog(double x, double base) { return moo::log(x, base); }
    MOOLIB_API double ln(double x) { return moo::ln(x); }

    MOOLIB_API double dsqrt(double x) { return moo::sqrt(x); }
    MOOLIB_API double dksqrt(double x, double k) { return moo::ksqrt(x, k); }
    MOOLIB_API double rounding(double x) { return moo::round(x); }
    MOOLIB_API double roundk(double x, int k) { return moo::roundk(x, k); }
}
// @formatter:on