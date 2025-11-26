void bozosort(int arr[], int n) {
    while (!is_sorted(arr, n)) {
        int i = rand() % n;
        int j = rand() % n;

        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}
