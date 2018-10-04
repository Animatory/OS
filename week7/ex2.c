#include <stdlib.h>

int main() {
    int n;
    scanf("%i", &n);
    int *arr = malloc(sizeof(int)*n);

    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d\n", arr[i]);
    }
    free(arr);
}

