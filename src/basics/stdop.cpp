
class moo
{
public:
    template <typename T> static T abs(T x)
    {
        return x < T(0) ? -x : x;
    }

    template <typename T> static T min(T a, T b)
    {
        return a < b ? a : b;
    }

    template <typename T> static T max(T a, T b)
    {
        return a > b ? a : b;
    }

    static int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

    static int lcm(int n, int k)
    {
        if (n == 0 || k == 0) return 0;
        int g = gcd(n, k);
        return abs(n / g * k);
    }
};

// @formatter:off
extern "C" {
    __declspec(dllexport) int abs_(int x) { return moo::abs<int>(x); }
    __declspec(dllexport) int min(int a, int b) { return moo::min<int>(a, b); }
    __declspec(dllexport) int max(int a, int b) { return moo::max<int>(a, b); }

    __declspec(dllexport) float abs_float(float x) { return moo::abs<float>(x); }
    __declspec(dllexport) float min_float(float a, float b) { return moo::min<float>(a, b); }
    __declspec(dllexport) float max_float(float a, float b) { return moo::max<float>(a, b); }

    __declspec(dllexport) double abs_double(double x) { return moo::abs<double>(x); }
    __declspec(dllexport) double min_double(double a, double b) { return moo::min<double>(a, b); }
    __declspec(dllexport) double max_double(double a, double b) { return moo::max<double>(a, b); }

    __declspec(dllexport) int gcd(int a, int b) { return moo::gcd(a, b); }
    __declspec(dllexport) int lcm(int n, int k) { return moo::lcm(n, k); }
}
// @formatter:on
