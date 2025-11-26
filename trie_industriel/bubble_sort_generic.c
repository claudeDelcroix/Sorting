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

            if (cmp(a, b) > 0) {
                swap_generic(a, b, size);
            }
        }
    }
}
