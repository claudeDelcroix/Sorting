#include <math.h>

void counting_sort_digit(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // compter les chiffres
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // cumul
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // remplir output (stable)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // recopier
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int get_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

void radix_sort(int arr[], int n) {
    int max = get_max(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
        counting_sort_digit(arr, n, exp);
}
