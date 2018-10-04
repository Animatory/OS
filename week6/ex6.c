#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    printf("Create first child\n");
    pipe(fd);
    int pid1 = fork();
    if (pid1 != 0) {
        printf("Create second child\n");
        int pid2 = fork();
        if (pid2) {
            printf("Record pid2 %d in buffer\n", pid2);
            write(fd[1], &pid2, sizeof(pid2));
        } else {
            printf("Magic is here\n");
            for (int i = 1; i < 1000; ++i) {
                printf("Magic appeared here %d times\n", i);
                sleep(1);
            }
        }

    } else {
        int *status;
        pid_t pid2 = 0;

        read(fd[0], &pid2, sizeof(pid2));
        printf("Read pid2 %d from buffer\n", pid2);
        waitpid(pid2, status, 0);
        sleep(2);
        kill(pid2, 1);

    }

}

