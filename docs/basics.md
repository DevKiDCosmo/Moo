# Basic Operation for Calculation - DOCS

### Operation that can be done directly

- $+$, $-$, $\cdot$, $\div$: Basic arithmetic operations.

### Operation that needs a function call

| Implemented | Function $\LaTeX$                                                   | Name                            | Data type (Output) | Data type (Input) | Unit Test | Function Call                                                | Supported Api |
|-------------|---------------------------------------------------------------------|---------------------------------|--------------------|-------------------|-----------|--------------------------------------------------------------|---------------|
| ✅           | $\displaystyle \left\lfloor \frac{a}{b} \right\rfloor$              | Integer division                | int64_t            | double, double    | ✅         | `moo::idiv`                                                  | Java, Python  |
| ❌           | $x^k$                                                               | Exponentiation                  | x                  | x, x              | ❌         | `moo::pow`                                                   |               |
| ❌           | $\sqrt{x}$                                                          | Square root                     | x                  | x                 | ❌         | `moo::sqrt`                                                  |               |
| ❌           | $\sqrt[k]{x}$                                                       | $k$-th root                     | x                  | x, x              | ❌         | `moo::sqrtk`                                                 |               |
| ❌           | $\ln(x)$                                                            | Natural logarithm               | x                  | x                 | ❌         | `moo::ln`                                                    |               |
| ❌           | $\log_k(x)$                                                         | Logarithm base $k$              | x                  | x, x              | ❌         | `moo::log`                                                   |               |
| ❌           | $\exp(x)$                                                           | Exponential function            | x                  | x                 | ❌         | `moo::exp`                                                   |               |
| ❌           | $\sin(x)$, $\cos(x)$, $\tan(x)$                                     | Trigonometric functions         | x                  | x                 | ❌         | `mod::sin`, etc.                                             |               |
| ❌           | $\arcsin(x)$, $\arccos(x)$, $\arctan(x)$                            | Inverse trigonometric functions | x                  | x                 | ❌         |                                                              |               |
| ❌           | $\sinh(x)$, $\cosh(x)$, $\tanh(x)$                                  | Hyperbolic functions            | x                  | x                 | ❌         |                                                              |               |
| ❌           | $\mathrm{arcsinh}(x)$, $\mathrm{arccosh}(x)$, $\mathrm{arctanh}(x)$ | Inverse hyperbolic functions    | x                  | x                 | ❌         |                                                              |               |
| ✅           | $\vert x \vert$                                                     | Absolute value                  | double             | double            | ✅         | `moo::absolute`                                              | Java, Python  |
| ✅           | $\lfloor x \rfloor$                                                 | Floor                           | double             | double            | ✅         | `moo::floor`                                                 | Java, Python  |
| ✅           | $\lceil x \rceil$                                                   | Ceil                            | double             | double            | ✅         | `moo::ceil`                                                  |               |
| ✅           | $\gcd(a, b)$                                                        | Greatest common divisor         | int64_t            | int64_t, int64_t  | ✅         | `moo::gcd`                                                   |               |
| ✅           | $\mathrm{lcm}(a, b)$                                                | Least common multiple           | int64_t            | int64_t, int64_t  | ✅         | `moo::lcm`                                                   |               |
| ✅           | $a \mod b$                                                          | Modulo                          | int64_t            | int64_t, int64_t  | ✅         | `moo::mod`                                                   |               |
| ✅           | $a \mod b$[^1]                                                      | Float Modulo                    | double             | double, double    | ✅         | `moo::flmod`                                                 |               |
| ✅           | $n!$                                                                | Factorial                       | int64_t            | int               | ✅         | `moo::fac`                                                   |               |
| ✅           | $\displaystyle\binom{n}{k}$                                         | Binomial coefficient            | int64_t            | int64_t, int64_t  | ✅         | `moo::binom`                                                 |               |
| ✅           | $\displaystyle\sigma(n)$                                            | Permutation                     | x                  | x                 | ❌         | `moo::permutation` `moo::fpermutation` `moo::genpermutation` |               |
| ✅           | $\max(a,b)$                                                         | Maximum                         | double             | double, double    | ✅         | `moo::max`                                                   |               |
| ✅           | $\min(a,b)$                                                         | Minimum                         | double             | double, double    | ✅         | `moo::min`                                                   |               |

[^1]: For `moo::flmod`, no unit test are done. But according to formulars
like $ \displaystyle a \mod b = a - b * \left\lfloor \frac{a}{b} \right\rfloor $ I am sure that the function is working
properly.