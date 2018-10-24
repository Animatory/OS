#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void notify(int signo) {
    printf("Signal caught.");
}

int main()
{
    signal(SIGINT, notify);
    while (1)
    {
        printf("hello world\n");
        sleep(1);
    }
    return 0;
}
