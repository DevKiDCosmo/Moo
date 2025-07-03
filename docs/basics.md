# Basic Operation for Calculation - DOCS

### Operation that can be done directly

- $+$, $-$, $\cdot$, $\div$: Basic arithmetic operations.

### Operation that needs a function call

| Implemented | Function $\LaTeX$                                                           | Name                            | Data type (Output) | Data type (Input) | Unit Test | Function Call                   | Api           | Dll                   | Supported Api | Notes |
|-------------|-----------------------------------------------------------------------------|---------------------------------|--------------------|-------------------|-----------|---------------------------------|---------------|-----------------------|---------------|-------|
| ✅           | $\displaystyle \left\lfloor \frac{a}{b} \right\rfloor$                      | Integer division                | int64_t            | double, double    | ✅         | `moo::idiv`                     | `idiv`        | `idiv`                | Java, Python  |       |
| ❌           | $x^k$                                                                       | Exponentiation                  | x                  | x, x              | ❌         | `moo::pow`                      |               |                       |               |       |
| ❌           | $\sqrt{x}$                                                                  | Square root                     | x                  | x                 | ❌         | `moo::sqrt`                     |               |                       |               |       |
| ❌           | $\sqrt[k]{x}$                                                               | $k$-th root                     | x                  | x, x              | ❌         | `moo::sqrtk`                    |               |                       |               |       |
| ❌           | $\ln(x)$                                                                    | Natural logarithm               | x                  | x                 | ❌         | `moo::ln`                       |               |                       |               |       |
| ❌           | $\log_k(x)$                                                                 | Logarithm base $k$              | x                  | x, x              | ❌         | `moo::log`                      |               |                       |               |       |
| ❌           | $\exp(x)$                                                                   | Exponential function            | x                  | x                 | ❌         | `moo::exp`                      |               |                       |               |       |
| ❌           | $\sin(x)$, $\cos(x)$, $\tan(x)$                                             | Trigonometric functions         | x                  | x                 | ❌         | `mod::sin`, etc.                |               |                       |               |       |
| ❌           | $\arcsin(x)$, $\arccos(x)$, $\arctan(x)$                                    | Inverse trigonometric functions | x                  | x                 | ❌         |                                 |               |                       |               |       |
| ❌           | $\sinh(x)$, $\cosh(x)$, $\tanh(x)$                                          | Hyperbolic functions            | x                  | x                 | ❌         |                                 |               |                       |               |       |
| ❌           | $\mathrm{arcsinh}(x)$, $\mathrm{arccosh}(x)$, $\mathrm{arctanh}(x)$         | Inverse hyperbolic functions    | x                  | x                 | ❌         |                                 |               |                       |               |       |
| ✅           | $\vert x \vert$                                                             | Absolute value                  | double             | double            | ✅         | `moo::absolute`                 | `abs`         | `absolute`            | Java, Python  |       |
| ✅           | $\lfloor x \rfloor$                                                         | Floor                           | double             | double            | ✅         | `moo::floor`                    | `floor`       | `dfloor`[^2]          | Java, Python  |       |
| ✅           | $\lceil x \rceil$                                                           | Ceil                            | double             | double            | ✅         | `moo::ceil`                     | `ceil`        | `dceil`[^2]           | Python        |       |
| ✅           | $\gcd(a, b)$                                                                | Greatest common divisor         | int64_t            | int64_t, int64_t  | ✅         | `moo::gcd`                      | `gcd`         | `gcd`                 | Python        |       |
| ✅           | $\mathrm{lcm}(a, b)$                                                        | Least common multiple           | int64_t            | int64_t, int64_t  | ✅         | `moo::lcm`                      | `lcm`         | `lcm`                 | Python        |       |
| ✅           | $a \mod b$                                                                  | Modulo                          | int64_t            | int64_t, int64_t  | ✅         | `moo::mod`                      | `mod`         | `mod`                 | Python        |       |
| ✅           | $a \mod b$[^1]                                                              | Float Modulo                    | double             | double, double    | ✅         | `moo::flmod`                    | `flmod`       | `flmod`               | Python        |       |
| ✅           | $n!$                                                                        | Factorial                       | int64_t            | int               | ✅         | `moo::fac`                      | `fac`         | `fac`                 | Python        |       |
| ✅           | $\displaystyle\binom{n}{k}$                                                 | Binomial coefficient            | int64_t            | int64_t, int64_t  | ✅         | `moo::binom`                    | `binom`       | `binom`               | Python        |       |
| ✅           | $\displaystyle L = \{ x = \mathrm{len}(\sigma(n)) \vert x \in \mathbb{N}\}$ | Factorial Table                 | int64_t*           | int               | ✅         | `moo::factable` `moo::clearptr` | `factable`    | `factable` `clearptr` | Python        |       |
| ✅           | $\displaystyle P (n,k) = \frac{n!}{(n - k)!}$                               | Permutation                     | int64_t            | int, int          | ✅         | `moo::permutation`              | `permutation` | `permutation`         | Python        |       |
| ✅           | $\displaystyle C (n,k) = \frac{n!}{k!(n - k)!}$                             | Combination                     | int64_t            | int, int          | ✅         | `moo::combination`              | `combination` | `combination`         | Python        |       |
| ✅           | $\displaystyle\sigma(n)$                                                    | Array of Permutation            | int64_t*           | int               | ✅         | `moo::genPerm` `moo::freePerm`  | `genPerm`     | `genPerm` `freePerm`  | Python        |       |
| ✅           | $\max(a,b)$                                                                 | Maximum                         | double             | double, double    | ✅         | `moo::max`                      | `max`         | `max`                 | Python        |       |
| ✅           | $\min(a,b)$                                                                 | Minimum                         | double             | double, double    | ✅         | `moo::min`                      | `min`         | `min`                 | Python        |       |
| ❌           |                                                                             | Prime factorization             |                    |                   | ❌         |                                 |               |                       |               |       |
| ❌           | $a^{-1} \mod m $                                                            | Inverse modulo                  |                    |                   | ❌         |                                 |               |                       |               |       |

is odd, is even, is prime, etc.

[^1]: For `moo::flmod`, no unit test are done. But according to formulars
like $ \displaystyle a \mod b = a - b \cdot \left\lfloor \frac{a}{b} \right\rfloor $ I am sure that the function is
working
properly.
[^2]: Names like `ceil` or `floor` cannot be used in the dll, because they are already in the `std` of C++. So `dceil`
and `dfloor` are used instead.