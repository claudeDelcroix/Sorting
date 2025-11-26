#include <stdlib.h>

void shuffle(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

int is_sorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            return 0;
    return 1;
}
void bogosort(int arr[], int n) {
    while (!is_sorted(arr, n)) {
        shuffle(arr, n);
    }
}
