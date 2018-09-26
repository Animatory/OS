#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
//    I don't know why this program does not work and how presence of sleep() affect on this because when I added this
//    program has broken
    int fd[2];
    printf("Create first child\n");
    int pid1 = fork();
    if (pid1 != 0) {
        printf("Create second child\n");
        int pid2 = fork();
        if (pid2 != 0) {
            printf("Record pid2 %d in buffer\n", pid2);
            write(fd[1], (const void *) pid2, sizeof(pid2));
        } else {
            printf("Magic is here\n");
            for (int i = 0; i < 10; ++i) {
                printf("Magic appears here %d times\n", i);
                sleep(1);
            }
        }

    } else {
        sleep(1);
        int *status;
        pid_t *pid2;

        read(fd[0], pid2, sizeof(pid2));
        printf("Read pid2 %d from buffer\n", *pid2);
        waitpid(*pid2, status, 0);
        sleep(2);
        kill(*pid2, 1);

    }

}