#include "../library.h"

class moo {
public:
    static int binomial_coefficient(int n, int k) {
        if (k == 0 || k == n) return 1;
        if (k < 0 || k > n) return 0;
        return binomial_coefficient(n - 1, k - 1) + binomial_coefficient(n - 1, k);
    }
};

extern "C" {
    __declspec(dllexport) int binomial_coefficient(int n, int k) {
        return moo::binomial_coefficient(n, k);
    }
}