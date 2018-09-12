#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void bash_loop(void);

char *bash_read_line(void);

char **bash_split_line(char *line);

int bash_execute(char **args);

int bash_cd(char **args);

int bash_exit(char **args);


int main(int argc, char **argv) {

    bash_loop();

    return 0;
}


void bash_loop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = bash_read_line();
        args = bash_split_line(line);
        status = bash_execute(args);

        free(line);
        free(args);
    } while (status);
}

char *bash_read_line() {
    char *line = NULL;
    ssize_t bufsize = 0; // have getline allocate a buffer for us
    getline(&line, &bufsize, stdin);
    return line;
}

char **bash_split_line(char *line) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    token = strtok(line, " \t\r\n\a");
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char *));
        }

        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[position] = NULL;
    return tokens;
}

int bash_launch(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("bash");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("bash");
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

char *builtin_str[] = {
        "cd",
        "exit"
};

int (*builtin_func[])(char **) = {
        &bash_cd,
        &bash_exit
};

int bash_num_builtins() {
    return sizeof(builtin_str) / sizeof(char *);
}

int bash_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "bash: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("bash");
        }
    }
    return 1;
}

int bash_exit(char **args) {
    return 0;
}

int bash_execute(char **args) {

    if (args[0] == NULL) {
        return 1;
    }

    for (int i = 0; i < bash_num_builtins(); i++) {
        if (strcmp(args[0], builtin_str[i]) == 0) {
            return (*builtin_func[i])(args);
        }
    }

    return bash_launch(args);
}