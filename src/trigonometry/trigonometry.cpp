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
}