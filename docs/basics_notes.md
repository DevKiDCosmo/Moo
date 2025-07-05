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

Second day on trying how to solve the problem mit nums.
My idea for today is to use for the function the type like `int` or `double`
instead of `moo::number` and then convert it to the desired number set.

For the type that should be used it is important to use the type that the function or
operation can handle. For example, if the function is $\vert x \vert$, it can handle `int`, `double`, and `long double`.
So it should use for the function call the type `double` or `long double` to handle the operation.
`int` would not be a good choice, because it can not handle negative numbers.

### Drafts to Variable and Calculation with Formulas.

Later: Integral, Formulas, Geometrics

`auto x = moo::var("x")`
`moo::interval(0, 10, 1, moo::sqrt(x), x, ...);`

Start, End, Step, Function, Variable...

Variable could be created by strings or by `moo::var("x")`.
Moo numbers etc.

```c++
struct moo::var_ {
    std::string name;
    moo::var(std::string n) : name(n) {}
    moo::num value;
};

moo::var (std::string name) {
    return moo::var_(name);
}

moo::varset (moo::var_ v, moo::num n) {
    v.value = n;
    return v;
}

struct moo::num {
    std::variant<double, int64_t, uint64_t, float, int32_t, uint32_t> value;
    moo::num(std::variant<double, int64_t, uint64_t, float, int32_t, uint32_t> v) : value(v) {}
    moo::num operator+(const moo::num& other) const { return moo::num(value + other.value); }
    moo::num operator-(const moo::num& other) const { return moo::num(value - other.value); }
    moo::num operator*(const moo::num& other) const { return moo::num(value * other.value); }
    moo::num operator/(const moo::num& other) const { return moo::num(value / other.value); }
};
```

Probably usig again Pointers and references to avoid copying the whole object and to make it C compactible.

```c++
typedef struct {
    int type; // 0=double, 1=int64_t, 2=uint64_t, 3=float, 4=int32_t, 5=uint32_t
    union {
        double d;
        int64_t i64;
        uint64_t u64;
        float f;
        int32_t i32;
        uint32_t u32;
    } value;
} moo_num;

typedef struct {
    char* name;    // Dynamisch allokierter String
    moo_num* value; // Pointer auf Zahl
} moo_var_;

#include <stdlib.h>
#include <string.h>
moo_var_* moo_var_create(const char* name, moo_num* value) {
    moo_var_* v = (moo_var_*)malloc(sizeof(moo_var_));
    v->name = strdup(name);
    v->value = value;
    return v;
}

void moo_var_free(moo_var_* v) {
    free(v->name);
    free(v->value);
    free(v);
}
```

Standard without `moo::var_`

```c++

int64_t function(int64_t x, int64_t y) {
    return x * y;
}

moo::i = nullptr; // Placeholder for the interval variable
int64_t x = 10;

auto* result = moo::interval(0, 10, 1, 2, function, x, moo::i);

// i is the interval variable, x is the variable for the function and constant
// Start, End, Step, Arg Legth, Function Name, Variable
```

```c++
std::vector<int64_t> moo::interval(
    int64_t start, int64_t end, int64_t step, int64_t argCount,
    std::function<int64_t(const std::vector<int64_t>&)> func,
    const std::vector<int64_t*>& vars
) {
    if (step <= 0 || start > end) {
        throw std::invalid_argument("Invalid interval arguments.");
    }
    if (!func) {
        throw std::invalid_argument("Function cannot be empty.");
    }
    if (vars.empty() || vars.size() != static_cast<size_t>(argCount)) {
        throw std::invalid_argument("Wrong size of vars.");
    }

    // Finde die Position der Intervall-Variable (nullptr)
    int64_t iterationIndex = -1;
    for (int64_t i = 0; i < argCount; ++i) {
        if (vars[i] == nullptr) {
            iterationIndex = i;
            break;
        }
    }
    if (iterationIndex == -1) {
        throw std::invalid_argument("Interval fixpoint nullptr not found in vars.");
    }

    std::vector<int64_t> result;
    std::vector<int64_t> varValues(argCount);

    // Initialisiere bekannte Variablen
    for (int64_t i = 0; i < argCount; ++i) {
        if (vars[i] != nullptr) {
            varValues[i] = *vars[i];
        }
    }

    for (int64_t i = start; i <= end; i += step) {
        varValues[iterationIndex] = i;
        result.push_back(func(varValues));
    }
    return result;
}
```

This doesn't need cleaning after execution, because the result is stored in a pointer.

The problem is that C cannot access the function of other language. So we create a small API in C++ that can be used in
C. We use the function: `moo::executefunc(funcname, params...)`. On the other side we can see what the dll wants to run
and execute it in the native API environment. The system could be a Socket or a listener that reads the function name of
the list.

The format will be like `[id, foo, 1, 2, 3]` and it is equal to the function call `foo(1, 2, 3)`.

If a listerner is implemented we should also add the function `moo::executedfunc(id)`. Because the listerner knows the
id it can delete the function from the list. Also the execution is always done from the smallest id to the highest id.

The `moo::executefunc` awaits in the program as long as it is not executed.