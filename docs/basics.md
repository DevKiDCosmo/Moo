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
class moo {
#include <variant>
#include <complex>
#include <cassert>

namespace moo {
public:
    // In numset
    using generic_number = std::variant<int, long, double, long double, std::complex<double>, Rational>;

    struct number { // can also be uninum or moo_number
        std::variant<int, double, long double, std::complex<double>, Rational> value;  
    };

    struct naturalNumber {
        int value;
    };
    
    // In basics for exponentiation
    template<typename Base, typename Exp>
    number exponentiation(Base base, Exp exp) {
        double base_val, exp_val;
    
        if constexpr (std::is_same_v<Base, number>)
            base_val = base.value;
        else if constexpr (std::is_same_v<Base, naturalNumber>)
            base_val = static_cast<double>(base.value);
        else {
            auto maybe_base = moo::conversenNatural(base);
            assert(maybe_base.has_value() && "Base conversion failed: Invalid type or num set for exponentiation");
            base_val = maybe_base.value().value;
        }
    
        if constexpr (std::is_same_v<Exp, number>)
            exp_val = exp.value;
        else if constexpr (std::is_same_v<Exp, naturalNumber>)
            exp_val = static_cast<double>(exp.value);
        else {
            auto maybe_exp = moo::conversenNatural(exp);
            assert(maybe_exp.has_value() && "Base conversion failed: Invalid type or num set for exponentiation");
            exp_val = maybe_exp.value().value;
        }
        
        double result = 1.0;
        double b = base.value;
        int e = exp.value;
        while (e > 0) {
            if (e % 2 == 1)
                result *= b;
            b *= b;
            e /= 2;
        }
        return number{result};
    }
    
    exponentiationdll(std::string base, std::string exp) {
        return exponentiation(moo::conversenNumber(moo::conversendll(base)), moo::conversenNatural(moo::conversendll(exp))).value;
    }
    
    extern "C" {
        double exponentiation(char* base_str, char* exp_str) {
            return exponentiationdll(base_str, exp_str);
        }    
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