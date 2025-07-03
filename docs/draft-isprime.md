```c++
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
```

Idea: Checking if a number is prime can be done by checking if it is divisible by any number from 2 to the square root
of the number. If it is not divisible by any of these numbers, then it is prime.