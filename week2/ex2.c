#include "stdio.h"

int main() {
    printf("Enter your string: ");
    char str[128];
    gets(str);

    int size = 0;
    while (str[size] != 0) {
        size++;
    }
    char str_reverse[size];
    int i = size;
    while (i > 0) {
        str_reverse[size-i] = str[i-1];
        i--;
    }
    str_reverse[size] = 0;
    printf(str_reverse);
}

