# Basic Operation for Calculation (Draft and Notes)

> Basics of mathematical operations that can be performed directly or require function calls.
> No formular or complex equation is needed, just the basic operations.

### Type Problem with C++

Creating a new type with the most compactibility to every calculation or creating a new type that can be used and
converted by every function to it destined type of number set.

For the use of dll, you must directly use the type `moo::number` for universal use, or for specific use, the correct
type of number set, like `moo::naturalNumber` for natural numbers. There is a small problem, C cannot handle `structs`.
To fix this problem, we use pointers to the `moo::number` type, which can be used in C as well.

For DLL usage, the function calls a function called `moo::conversendll`. It converts it to the nearest define type.
With a chain like `moo::conversenNatural(moo::conversendll(x))`,
it can convert the number to the nearest defined type in the number set, if the number is fitting in the restrainments.

For ease, the `moo::conversendll` use a string to process instead creating the same function over and over for different
types.

Given the following code snippet, we can see how to handle different number types and perform exponentiation:

```cpp
// May contain errors - this is a draft and notes for the basics of mathematical operations in C++ with MooLib.
assert(false && "This is a draft and notes for the basics of mathematical operations in C++ with MooLib.");
#include <variant>
#include <complex>
#include <cassert>
#include <string>
#include <optional>
#include <cmath>
#include <iostream>

class moo {
public:
    // In numset
    struct rational {
        long long numerator;
        long long denominator;

        rational(long long num = 0, long long denom = 1) : numerator(num), denominator(denom) {
            if (denominator == 0) {
                throw std::invalid_argument("Denominator cannot be 0");
            }
        }
    };
    
    using generic_number = std::variant<int, long, double, long double, std::complex<double>, rational>;

    struct number { // can also be uninum or moo_number
        std::variant<int, double, long double, std::complex<double>, rational> value;  
    };

    struct naturalNumber {
        int value;
    };
    
    // In conversen
    static double conversenDouble(const std::variant<int, double, long double, std::complex<double>, Rational>& v) {
        return std::visit([](auto&& val) -> double {
            using T = std::decay_t<decltype(val)>;
            if constexpr (std::is_same_v<T, std::complex<double>>) {
                return val.real(); // Nur Realteil
            } else if constexpr (std::is_same_v<T, Rational>) {
                return val.to_double(); // Dummy-Methode
            } else {
                return static_cast<double>(val);
            }
        }, v);
    }
    
    static std::optional<naturalNumber> conversenNatural(const std::string& str) {
        try {
            return naturalNumber{ std::stoi(str) };
        } catch (...) {
            return std::nullopt;
        }
    }

    static std::optional<number> conversenNumber(const std::string& str) {
        try {
            return number{ std::stod(str) };
        } catch (...) {
            return std::nullopt;
        }
    }
    
    ...
    
    template<typename Variant>
    static double extractDouble(const Variant& var) {
        static_assert(std::variant_size_v<Variant> > 0, "Variant must not be empty.");
        return std::visit([](auto&& val) -> double {
            using T = std::decay_t<decltype(val)>;
               if constexpr (std::is_same_v<T, std::complex<double>>) {
                   return val.real();
               } else if constexpr (std::is_same_v<T, Rational>) {
                   return val.to_double();
               } else {
                   return static_cast<double>(val);
               }
        }, var);
    }

    
    // In basics for exponentiation
    template<typename Base, typename Exp>
    static number exponentiation(Base base, Exp exp) {
        
        // Logic for verifying types and extracting values
        static_assert(std::is_same_v<Base, number> || std::is_same_v<Base, naturalNumber>, "Base must be number or naturalNumber.");
        static_assert(std::is_same_v<Exp, naturalNumber>, "Exponent must be naturalNumber.");
        
        moo::conversenNumber(base);
        moo::conversenNatural(exp);
        
        assert(moo::extractDouble(exp.value) >= 0 && "Exponent must be non-negative.");
        
        
        double result = 1.0;
        double b = moo::extractDouble(base.value);
        int e = moo::extractDouble(exp.value);
        while (e > 0) {
            if (e % 2 == 1)
                result *= b;
            b *= b;
            e /= 2;
        }
        return number{result};
    }
    
    double exponentiationdll(const std::string& base, const std::string& exp) {
        auto base_num = moo::conversenNumber(moo::conversendll(base));
        auto exp_num = moo::conversenNatural(moo::conversendll(exp));
        auto result = exponentiation(base_num, exp_num);
        return moo::conversenDouble(result.value);
    }
    
}

// MOOLIB_API from library.h for DLL export with __declspec(dllexport)
extern "C" {
    MOOLIB_API double exponentiation(char* base_str, char* exp_str) {
        return exponentiationdll(base_str, exp_str);
    }    
}

```

E.g.:

```cpp
#include <moo.hpp>

moo::number x = {2.42f};
moo::naturalNumber k = {5};
auto result = moo::exponentiation(x, k); // Result: number{32.0}
```

and with DLL usage:

```cpp
#include <windows.h>
#include <iostream>

typedef double (*exponentiation_func)(char*, char*);

int main() {
    HMODULE hMoo = LoadLibraryA("moo.dll");
    if (!hMoo) {
        std::cerr << "Error: moo.dll cannot be loaded." << std::endl;
        return 1;
    }

    exponentiation_func exponentiation = (exponentiation_func)GetProcAddress(hMoo, "exponentiation");
    if (!exponentiation) {
        std::cerr << "Error: Function exponentiation cannot be found." << std::endl;
        FreeLibrary(hMoo);
        return 1;
    }

    char base[] = "2.42";
    char exp[] = "5";
    double result = exponentiation(base, exp);
    std::cout << "Result: " << result << std::endl; // Result: 32.0

    FreeLibrary(hMoo);
    return 0;
}
```

### Operation that can be done directly

- $+$, $-$, $\cdot$, $\div$: Basic arithmetic operations.

### Operation that needs a function call

- $x^k$: Exponentiation. - Calculating by $\ln \to x^k \equiv e^{k \cdot \ln(x)}$
- $\sqrt{x}$: Square root of $x$.
- $\sqrt[k]{x}$: $k$-th root of $x$.
- $\ln(x)$: Natural logarithm of $x$.
- $\log_k(x)$: Logarithm of $x$ to the base $k$.
- $\exp(x)$: Exponential function, $e^x$.
- $\sin(x)$, $\cos(x)$, $\tan(x)$: Trigonometric functions.
- $\arcsin(x)$, $\arccos(x)$, $\arctan(x)$: Inverse trigonometric functions.
- $\sinh(x)$, $\cosh(x)$, $\tanh(x)$: Hyperbolic functions.
- $\mathrm{arcsinh}{(x)}, \mathrm{arccosh}{(x)}, \mathrm{arctanh}{(x)}$: Inverse hyperbolische Funktionen.
- ✅ $\vert x \vert$: Absolute value of $x$.
- $\lfloor x \rfloor$: Floor function, the greatest integer less than or equal to $x$.
- $\lceil x \rceil$: Ceiling function, the smallest integer greater than or equal to $x$.
- ✅ $\gcd(a, b)$: Greatest common divisor of $a$ and $b$.
- ✅ $\mathrm{lcm}(a, b)$: Least common multiple of $a$ and $b$.
- $\mathrm{mod}(a, b)$: Modulus operation, $a \mod b$.
- ✅ $n!$: Factorial of $n$, denoted as $n!$.
- ✅ $\displaystyle\binom{n}{k}$: Binomial coefficient, the number of ways to choose $k$ elements from a set of $n$
  elements.
- $\displaystyle\sigma(n) : n = \{x,_1, x_2, \dots, x_n: x \in \mathbb{R}\}$: Permutation, the number of ways to
  arrange $k$ elements from a set of $n$ elements.