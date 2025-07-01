# Basic Operation for Calculation - DOCS

### Operation that can be done directly

- $+$, $-$, $\cdot$, $\div$: Basic arithmetic operations.

### Operation that needs a function call

| Implemented | Function $\LaTeX$                                                   | Name                            | Data type (Output) | Data type (Input) |
|-------------|---------------------------------------------------------------------|---------------------------------|--------------------|-------------------|
| ❌           | $x^k$                                                               | Exponentiation                  | x                  | x, x              |
| ❌           | $\sqrt{x}$                                                          | Square root                     | x                  | x                 |
| ❌           | $\sqrt[k]{x}$                                                       | $k$-th root                     | x                  | x, x              |
| ❌           | $\ln(x)$                                                            | Natural logarithm               | x                  | x                 |
| ❌           | $\log_k(x)$                                                         | Logarithm base $k$              | x                  | x, x              |
| ❌           | $\exp(x)$                                                           | Exponential function            | x                  | x                 |
| ❌           | $\sin(x)$, $\cos(x)$, $\tan(x)$                                     | Trigonometric functions         | x                  | x                 |
| ❌           | $\arcsin(x)$, $\arccos(x)$, $\arctan(x)$                            | Inverse trigonometric functions | x                  | x                 |
| ❌           | $\sinh(x)$, $\cosh(x)$, $\tanh(x)$                                  | Hyperbolic functions            | x                  | x                 |
| ❌           | $\mathrm{arcsinh}(x)$, $\mathrm{arccosh}(x)$, $\mathrm{arctanh}(x)$ | Inverse hyperbolic functions    | x                  | x                 |
| ✅           | $\vert x \vert$                                                     | Absolute value                  | int64_t            | int64_t           |
| ✅           | $\lfloor x \rfloor$                                                 | Floor                           | double             | double            |
| ✅           | $\lceil x \rceil$                                                   | Ceil                            | double             | double            |
| ✅           | $\gcd(a, b)$                                                        | Greatest common divisor         | int64_t            | int64_t, int64_t  |
| ✅           | $\mathrm{lcm}(a, b)$                                                | Least common multiple           | int64_t            | int64_t, int64_t  |
| ✅           | $a \mod b$                                                          | Modulo                          | int64_t            | int64_t, int64_t  |
| ✅           | $a \mod b$[^1]                                                      | Float Modulo                    | double             | double, double    |
| ✅           | $n!$                                                                | Factorial                       | int64_t            | int               |
| ✅           | $\displaystyle\binom{n}{k}$                                         | Binomial coefficient            | int64_t            | int64_t, int64_t  |
| ❌           | $\displaystyle\sigma(n)$                                            | Permutation                     | x                  | x                 |
| ✅           | $\max(a,b)$                                                         | Maximum                         | double             | double, double    |
| ✅           | $\min(a,b)$                                                         | Minimum                         | double             | double, double    |

Ganzzahldivision.

[^1]: For `moo::flmod`, no unit test are done. But according to formulars
like $ \displaystyle a \mod b = a - b * \left\lfloor \frac{a}{b} \right\rfloor $ I am sure that the function is working
properly.