#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void bash_loop();
char* bash_read_line();
int bash_execute(char *command);

int main(void) {
    bash_loop();

    return 0;
}

void bash_loop() {
    char *line;
    int status = 1;

    do {
        printf("> ");
        line = bash_read_line();
        status = bash_execute(line);

        free(line);
    } while (!status);
}

char* bash_read_line() {
    char *line = NULL;
    ssize_t bufsize = 0; // have getline allocate a buffer for us
    getline(&line, &bufsize, stdin);
    return line;
}

int bash_execute(char *command) {
    int status = 0;
    if (strcmp(command, "exit\n") == 0) {
        status = 1;
    } else {
        if (system(command) == 1) {
            perror("bash");
        };
    }
    return status;
}







