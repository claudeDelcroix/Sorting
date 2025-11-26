void stooge_sort(int arr[], int left, int right) {
    if (arr[left] > arr[right]) {
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
    }

    if (right - left + 1 > 2) {
        int third = (right - left + 1) / 3;

        stooge_sort(arr, left, right - third);
        stooge_sort(arr, left + third, right);
        stooge_sort(arr, left, right - third);
    }
}
