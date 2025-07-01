#include <cstdint>

class moo
{
public:
    static int64_t binom(int64_t n, int64_t k)
    {
        if (k == 0 || k == n) return 1;
        if (k < 0 || k > n) return 0;
        return binom(n - 1, k - 1) + binom(n - 1, k);
    }
};

// @formatter:off
extern "C" {
    __declspec(dllexport) int64_t binom(int64_t n, int64_t k)
    {
        return moo::binom(n, k);
    }
}
// @formatter:on