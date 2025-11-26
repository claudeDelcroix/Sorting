#include <stdlib.h>

void pigeonhole_sort(int arr[], int n) {
    int min = arr[0], max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int range = max - min + 1;
    int *holes = calloc(range, sizeof(int));

    // compter occurrences
    for (int i = 0; i < n; i++)
        holes[arr[i] - min]++;

    // remplir arr trié
    int index = 0;
    for (int i = 0; i < range; i++)
        while (holes[i]--)
            arr[index++] = i + min;

    free(holes);
}
