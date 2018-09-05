#include <stdio.h>

int partition(int arr[], int low, int high) {
    int p, i, j, t;
    p = arr[low];
    i = low - 1;
    j = high + 1;
    while (1 > 0){
        do {
            i++;
        }while (arr[i] < p);

        do {
            j--;
        } while (arr[j] > p);

        if (i >= j) {
            return j;
        }

        t = arr[j];
        arr[j] = arr[i];
        arr[i] = t;
    }
}

void do_quick_sort(int arr[], int low, int high){
    if (low < high) {
        int p = partition(arr, low, high);
        do_quick_sort(arr, low, p);
        do_quick_sort(arr, p+1, high);
    }

}

void quick_sort(int arr[], int n) {
    do_quick_sort(arr, 0, n-1);

}

int main() {
    int arr[] = {3, 0, 6, 23, 86,1, -34, 8, 12, -9};
    int n = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr, n);
    for (int i = 0; i < n; ++i) {
        printf("%d, ", arr[i]);
    }
    return 0;
}
