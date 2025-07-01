#include <cstdint>

class moo
{
public:
    static int64_t factorial(int n)
    {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    }
};

// @formatter:off
extern "C" {
    __declspec(dllexport) int64_t fac(int n)
    {
        return moo::factorial(n);
    }
}
// @formatter:on