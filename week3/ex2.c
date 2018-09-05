#include <stdio.h>

void bubble_sort(int arr[], int n) {
    int i, j, t;
    for (i = 0; i < (n - 1); i++) {
        for (j = 0; j < (n - i - 1); j++) {
            if (arr[j] > arr[j + 1]) {
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

int main() {
    int arr[] = {3, 0, 6, 23, 86,1, -34, 8, 12, -9};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr, n);
    for (int i = 0; i < n; ++i) {
        printf("%d, ", arr[i]);
    }
    return 0;
}

