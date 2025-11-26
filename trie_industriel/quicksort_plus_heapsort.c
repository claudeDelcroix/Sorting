#include <math.h>

void heapify_intro(int arr[], int n, int i);

void heapsort_intro(int arr[], int n) {
    for (int i = n/2-1; i >= 0; i--)
        heapify_intro(arr, n, i);

    for (int i = n-1; i > 0; i--) {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify_intro(arr, i, 0);
    }
}

void heapify_intro(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        int tmp = arr[i]; arr[i] = arr[largest]; arr[largest] = tmp;
        heapify_intro(arr, n, largest);
    }
}

void introsort(int arr[], int n, int depth_limit) {
    if (n <= 1) return;

    if (depth_limit == 0) {
        heapsort_intro(arr, n);
        return;
    }

    int pivot = arr[n/2];
    int i = 0, j = n - 1;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
            i++; j--;
        }
    }

    if (j > 0)
        introsort(arr, j + 1, depth_limit - 1);

    if (i < n)
        introsort(arr + i, n - i, depth_limit - 1);
}

void sort_introsort(int arr[], int n) {
    int depth = 2 * log(n);
    introsort(arr, n, depth);
}
