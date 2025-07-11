#include "../moo.hpp"
#include "../export.h"

double moo::sine(double x) {
    double term = x;
    double sum  = x;
    int    n    = 1;
    for (int i = 1; i <= 10; ++i) {
        term *= -x * x / ((2 * n) * (2 * n + 1));
        sum += term;
        n++;
    }
    return sum;
}

double moo::cosine(double x) {
    double term = 1.0;
    double sum  = 1.0;
    int    n    = 1;
    for (int i = 1; i <= 10; ++i) {
        term *= -x * x / ((2 * n - 1) * (2 * n));
        sum += term;
        n++;
    }
    return sum;
}

double moo::tangent(double x) {
    double sin_x = sine(x);
    double cos_x = cosine(x);
    if (cos_x == 0) {
        throw std::runtime_error("Division by zero in tangent calculation");
    }
    return sin_x / cos_x;
}

double moo::arcsine(double x) {
    // Normalize x to the range [-1, 1]
    if (x > 1) {
        x = x - floor(x);
    } else {
        x = x < -1 ? x + ceil(x) : x;
    }

    double term = x;
    double sum  = x;
    int    n    = 1;
    for (int i = 1; i <= 10; ++i) {
        term *= (x * x * (2 * n - 1)) / ((2 * n) * (2 * n + 1));
        sum += term;
        n++;
    }
    return sum;
}

double moo::arccosine(double x) {
    return moo::pi()/2 - arcsine(x);
}

double moo::arctangent(double x) {
    double term = x;
    double sum  = x;
    int sign = -1;
    for (int n = 1; n <= 10; ++n) {
        term = pow(x, 2 * n + 1) / (2 * n + 1);
        sum += sign * term;
        sign *= -1;
    }
    return sum;
}

extern "C" {
MOOLIB_API double sine(double x) {
    return moo::sine(x);
}

MOOLIB_API double cosine(double x) {
    return moo::cosine(x);
}

MOOLIB_API double tangent(double x) {
    return moo::tangent(x);
}

MOOLIB_API double arcsine(double x) {
    return moo::arcsine(x);
}
}