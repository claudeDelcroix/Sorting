#include <stdlib.h>

void counting_sort(int arr[], int n, int max_value) {
    int *count = calloc(max_value + 1, sizeof(int));
    int *output = malloc(n * sizeof(int));

    // compter les occurrences
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // positions cumulées
    for (int i = 1; i <= max_value; i++)
        count[i] += count[i - 1];

    // remplir le tableau trié
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // recopier dans arr
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    free(count);
    free(output);
}
