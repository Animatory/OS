#include "stdio.h"

int main(){
    printf("Enter two integers: ");
    int a, b;
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("%d %d", a, b);
}

void swap(int *a, int *b) {
    int t = *b;
    *b = *a;
    *a = t;

}