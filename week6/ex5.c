#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pids[2];
    int pid = fork();
    if (pid == 0) {
        pids[1] = pid;
        while (1) {
            printf("I'm alive\n");
            sleep(1);
        }
    } else {
        pids[0] = pid;
        sleep(10);
        kill(pids[1], 1);
    }
}
