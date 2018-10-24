#include "stdio.h"

int main(){
    printf("Enter n: ");
    int n, i, j;
    scanf("%d", &n);

    for (i = n; i > 0; i--) {
        for (j = 0; j < i; j++) {
            printf(" ");
        }
        for (j = (n-i+1)*2-1; j > 0; j--) {
            printf("*");
        }
        for (j = 0; j < i; j++) {
            printf(" ");
        }
        printf("\n");
    }
}

