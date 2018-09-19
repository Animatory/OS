#include "stdio.h"
#include <stdio.h>

int i = 32;

int main(int i, char *b[]){
    printf("Enter two integers: ");
    printf("%d", i);
}

void swap(int *a, int *b) {
    int t = *b;
    *b = *a;
    *a = t;

}