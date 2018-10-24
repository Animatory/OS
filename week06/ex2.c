#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int fd[2];
    char input[] = "Text from input";
    char output[256];

    pipe(fd);

    write(fd[1], input, sizeof(input));

    int pid = fork();
    if (pid == 0) {
        read(fd[0], output, sizeof(output));
        printf("Child read from pipe: %s", output);
    }
}
