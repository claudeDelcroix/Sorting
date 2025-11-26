#include "sorts.h"
#include <stdlib.h>
#include <math.h>

/* ============================================================
   ======================= TRIS SIMPLES ========================
   ============================================================ */

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void cocktail_sort(int arr[], int n) {
    int start = 0, end = n - 1;
    int swapped = 1;

    while (swapped) {
        swapped = 0;

        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                int t = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = t;
                swapped = 1;
            }
        }
        if (!swapped) break;

        swapped = 0;
        end--;

        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                int t = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = t;
                swapped = 1;
            }
        }
        start++;
    }
}

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < min_index)
                min_index = j;
        }

        int tmp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = tmp;
    }
}

void gnome_sort(int arr[], int n) {
    int i = 0;

    while (i < n) {
        if (i == 0 || arr[i] >= arr[i - 1]) {
            i++;
        } else {
            int tmp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = tmp;
            i--;
        }
    }
}

int next_gap(int gap) {
    gap = (gap * 10) / 13;
    if (gap < 1) return 1;
    return gap;
}

void comb_sort(int arr[], int n) {
    int gap = n;
    int swapped = 1;

    while (gap != 1 || swapped) {
        gap = next_gap(gap);
        swapped = 0;

        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                int tmp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = tmp;
                swapped = 1;
            }
        }
    }
}


/* ============================================================
   ======================= TRIS EFFICACES ======================
   ============================================================ */

/* -------------------------- QUICKSORT ----------------------- */

void quicksort(int arr[], int left, int right) {
    if (left >= right) return;

    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j) quicksort(arr, left, j);
    if (i < right) quicksort(arr, i, right);
}

/* --------------------------- MERGESORT ----------------------- */

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergesort(int arr[], int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergesort(arr, left, mid);
    mergesort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

/* --------------------------- HEAPSORT ----------------------- */

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n-1; i > 0; i--) {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify(arr, i, 0);
    }
}

/* --------------------------- SHELL SORT ----------------------- */

void shell_sort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int tmp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j-gap] > tmp; j -= gap)
                arr[j] = arr[j-gap];

            arr[j] = tmp;
        }
    }
}

#include "sorts.h"
#include <stdlib.h>
#include <math.h>

/* ============================================================
   ================= TRIS NON COMPARATIFS =====================
   ============================================================ */

/* --------------------------- COUNTING SORT ------------------ */

void counting_sort(int arr[], int n, int max_value) {
    int *count = calloc(max_value + 1, sizeof(int));
    int *output = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= max_value; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    free(count);
    free(output);
}

/* --------------------------- RADIX SORT --------------------- */

int get_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

void counting_sort_digit(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radix_sort(int arr[], int n) {
    int max = get_max(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
        counting_sort_digit(arr, n, exp);
}

/* --------------------------- PIGEONHOLE SORT ---------------- */

void pigeonhole_sort(int arr[], int n) {
    int min = arr[0], max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int range = max - min + 1;
    int *holes = calloc(range, sizeof(int));

    for (int i = 0; i < n; i++)
        holes[arr[i] - min]++;

    int index = 0;
    for (int i = 0; i < range; i++)
        while (holes[i]--)
            arr[index++] = i + min;

    free(holes);
}

/* ============================================================
   ======================= TRIS EXOTIQUES =====================
   ============================================================ */

int is_sorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1]) return 0;
    return 1;
}

void shuffle(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

void bogosort(int arr[], int n) {
    while (!is_sorted(arr, n))
        shuffle(arr, n);
}

void bozosort(int arr[], int n) {
    while (!is_sorted(arr, n)) {
        int i = rand() % n;
        int j = rand() % n;
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

void stooge_sort(int arr[], int left, int right) {
    if (arr[left] > arr[right]) {
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
    }

    if (right - left + 1 > 2) {
        int t = (right - left + 1) / 3;
        stooge_sort(arr, left, right - t);
        stooge_sort(arr, left + t, right);
        stooge_sort(arr, left, right - t);
    }
}

/* ============================================================
   =================== TRIS AVANCES / BONUS ===================
   ============================================================ */

/* ------------------------ GENERIC SORT --------------------- */

void swap_generic(void *a, void *b, size_t size) {
    unsigned char *p = a, *q = b, tmp;
    for (size_t i = 0; i < size; i++) {
        tmp = p[i];
        p[i] = q[i];
        q[i] = tmp;
    }
}

void bubble_sort_generic(void *base, size_t n, size_t size,
                         int (*cmp)(const void*, const void*)) {

    unsigned char *arr = base;

    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            void *a = arr + j * size;
            void *b = arr + (j + 1) * size;

            if (cmp(a, b) > 0)
                swap_generic(a, b, size);
        }
    }
}

/* -------------------------- INTROSORT ---------------------- */

void heapify_intro(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        int tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;
        heapify_intro(arr, n, largest);
    }
}

void heapsort_intro(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify_intro(arr, n, i);

    for (int i = n-1; i > 0; i--) {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify_intro(arr, i, 0);
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
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++; j--;
        }
    }

    if (j > 0) introsort(arr, j + 1, depth_limit - 1);
    if (i < n) introsort(arr + i, n - i, depth_limit - 1);
}

void sort_introsort(int arr[], int n) {
    int depth = 2 * log(n);
    introsort(arr, n, depth);
}

/* --------------------------- TIMSORT ------------------------ */

void insertion_sort_run(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge_timsort(int arr[], int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];

    for (int i = 0; i < len1; i++) left[i] = arr[l + i];
    for (int i = 0; i < len2; i++) right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < len1 && j < len2)
        arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];

    while (i < len1) arr[k++] = left[i++];
    while (j < len2) arr[k++] = right[j++];
}

void timsort(int arr[], int n) {
    for (int i = 0; i < n; i += RUN)
        insertion_sort_run(arr, i, (i + RUN - 1 < n - 1) ? i + RUN - 1 : n - 1);

    for (int size = RUN; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < n - 1) ? left + 2 * size - 1 : n - 1;

            if (mid < right)
                merge_timsort(arr, left, mid, right);
        }
    }
}
