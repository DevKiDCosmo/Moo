```c++
#include <cstdint>
#include <cstdlib>

extern "C" {

__declspec(dllexport)
int** generate_permutations(int n, int* count) {
    if (n <= 0) {
        *count = 0;
        return nullptr;
    }

    int total = 1;
    for (int i = 2; i <= n; ++i)
        total *= i;

    *count = total;

    // Speicher für alle Permutationen (2D-Array)
    int** result = (int**)malloc(sizeof(int*) * total);
    for (int i = 0; i < total; ++i)
        result[i] = (int*)malloc(sizeof(int) * n);

    // Arbeitsarray und Zähler
    int* a = (int*)malloc(sizeof(int) * n);
    int* c = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i)
        a[i] = i + 1;

    // Erste Permutation speichern
    for (int i = 0; i < n; ++i)
        result[0][i] = a[i];

    int idx = 1;
    int i = 0;

    while (i < n) {
        if (c[i] < i) {
            if (i % 2 == 0) {
                int tmp = a[0]; a[0] = a[i]; a[i] = tmp;
            } else {
                int tmp = a[c[i]]; a[c[i]] = a[i]; a[i] = tmp;
            }

            for (int j = 0; j < n; ++j)
                result[idx][j] = a[j];
            ++idx;

            ++c[i];
            i = 0;
        } else {
            c[i] = 0;
            ++i;
        }
    }

    free(a);
    free(c);
    return result;
}

}

```