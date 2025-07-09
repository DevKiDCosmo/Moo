# Intervals

Mit der `moo::interval` Funktion können Sie Wertebereiche (Intervalle) effizient durchlaufen und für jeden Wert eine
Funktion ausführen lassen. Dies ist besonders nützlich, wenn Sie Berechnungen oder Auswertungen für eine Serie von
Werten automatisieren möchten.

### Funktionssignatur

```c++
std::vector<int64_t> moo::interval(
    int64_t start, int64_t end, int64_t step, int64_t argCount,
    std::function<int64_t(const std::vector<int64_t>&)> func,
    const std::vector<int64_t*>& vars
);
```

| Implemented | Function $\LaTeX$      | Name     | Data type (Output) | Data type (Input)                                      | Unit Test | Function Call   | Api        | Dll          | Notes                   |
|-------------|------------------------|----------|--------------------|--------------------------------------------------------|-----------|-----------------|------------|--------------|-------------------------|
| ✅           | $ f (x), x \in [a, b]$ | Interval | int64_t*           | int64_t, int64_t, int64_t, int64_t, function, int64_t* | ❌         | `moo::interval` | `interval` | `interval_c` | Is not production ready |

-

executefunc(const char* name, const int64_t* params, int64_t param_count);
executedfunc(int64_t id, double result);
get_all_func_calls(int64_t* out_count);
free_func_calls(func_call_c* arr, int64_t count);


Current Problem:

How to time the execution. Interval -> execute function -> Interval done -> return value

Intervals must await until function execution is done. This means that the function must be executed in a separate thread or...