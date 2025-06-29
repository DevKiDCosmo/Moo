#include "../library.h"

class moo {
public:
    static int factorial(int n) {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    }
};

extern "C" {
    __declspec(dllexport) int factorial(int n) {
        return moo::factorial(n);
    }
}