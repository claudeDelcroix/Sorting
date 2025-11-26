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
