#include <stdio.h>
#include <unistd.h>


int main() {
    int n = 2211;
    int pid = fork();
    printf("Hello from %s [%d - %d]\n", (n == pid) ? "parent" : "child", pid, n);
    return 0;
}

