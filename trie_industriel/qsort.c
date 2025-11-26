#include <stdlib.h>

int cmp_int(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return x - y;   // tri croissant
}

void sort_with_qsort(int arr[], int n) {
    qsort(arr, n, sizeof(int), cmp_int);
}
