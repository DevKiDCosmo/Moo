# Grammar

```c++
int x = 30;
std::string function = "f(x, y): x + y";
int = moo::execute(function)(x, 5);
```

auto* result = moo::interval(0, 10, 1, 2, moo::execute(function), x, moo::i);
// Result: // 
```

How to parse math effectively in C++? The `moo::execute` function takes a string representation of a mathematical
function and evaluates it over a specified range with given parameters.

Function have a distinct syntax: `_(params...): expression`. If only expression is given, then it is assumed that all
variables are constant that are defined in the runtime. With a function, the variables are treated as parameters and can
be calculated with functions like `moo::interval`.

```c++
std::function<int64_t(const std::vector<int64_t>&)> moo::execute(std::string function) {

}
int64_t moo::execute(std::string function)(int x, int y) {
    // Implementation that parses the function string and returns a callable function
}
```

Moo execute creates a function that can be used to evaluate the expression with given parameters.