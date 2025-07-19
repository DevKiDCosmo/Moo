#include "../moo.hpp"
#include "../export.h"

double moo::pi() {
    return 3.14159265358979323846;
}

double* moo::primefac(double x) {
    std::vector<double> tmp_factors;
    double              factor = 2;
    while (x > 1) {
        if (static_cast<int64_t>(x) % static_cast<int64_t>(factor) == 0) {
            tmp_factors.push_back(factor);
            x /= factor;
        } else {
            factor++;
        }
    }
    double* factors = new double[tmp_factors.size()];
    for (size_t i = 0; i < tmp_factors.size(); ++i) {
        factors[i] = tmp_factors[i];
    }
    return factors;
}

extern "C" {
MOOLIB_API double pi() {
    return moo::pi();
}

MOOLIB_API double* primefac(double x) {
    return moo::primefac(x);
}
}