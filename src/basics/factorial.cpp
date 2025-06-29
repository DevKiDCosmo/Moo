class moo
{
public:
    static int factorial(int n)
    {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    }
};

// @formatter:off
extern "C" {
    __declspec(dllexport) int fac(int n)
    {
        return moo::factorial(n);
    }
}
// @formatter:on
