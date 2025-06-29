#include "../library.h"
#include <cmath>
#include <cstdint>
#include <limits>

extern "C" {

    // Schnelle, aber ungenaue Quadratwurzel (Approximation)
    double _sqrt(float number) {
        if (number < 0.0f) return std::numeric_limits<double>::quiet_NaN();
        union { uint32_t i; float x; } u;
        u.x = number;
        u.i = (1 << 29) + (u.i >> 1) - (1 << 22);
        return static_cast<double>(u.x);
    }

    // Schnelle Inverses Quadratwurzel (Fast Inverse Square Root)
    double _invsqrt(float number) {
        if (number <= 0.0f) return std::numeric_limits<double>::quiet_NaN();
        float x2 = number * 0.5f;
        union { uint32_t i; float x; } u;
        u.x = number;
        u.i = 0x5f3759df - (u.i >> 1);
        u.x *= 1.5f - (x2 * u.x * u.x);
        return static_cast<double>(u.x);
    }

    // Ganzzahliges Potenzieren (nur für positive Exponenten)
    double _pow(double base, int exp) {
        if (exp < 0) return 1.0 / _pow(base, -exp);
        double result = 1.0;
        while (exp--) result *= base;
        return result;
    }

    // N-te Wurzel durch Newton-Verfahren
    double _nroot(double number, int n, int iterations) {
        if (number < 0.0 && n % 2 == 0) return std::numeric_limits<double>::quiet_NaN(); // keine gerade Wurzel negativer Zahlen
        if (number == 0.0) return 0.0;
        double x = number / n;
        for (int i = 0; i < iterations; ++i) {
            x = ((n - 1) * x + number / _pow(x, n - 1)) / n;
        }
        return x;
    }

}
