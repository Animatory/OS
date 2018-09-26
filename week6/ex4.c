#include<stdio.h> 
#include<signal.h> 
#include<unistd.h>
  
void notify_sigint(int signo) {
    printf("SIGINT handled!\n");
}

void notify_sigkill(int signo) {
    printf("SIGKILL handled!\n");
}

void notify_sigstop(int signo) {
    printf("SIGSTOP handled!\n");
}

void notify_sigusr1(int signo) {
    printf("SIGUSR1 handled!\n");
}

int main() { 
    signal(SIGINT, notify_sigint); 
    signal(SIGKILL, notify_sigkill); 
    signal(SIGSTOP, notify_sigstop); 
    signal(SIGUSR1, notify_sigusr1); 
    while (1) 
    { 
        sleep(1); 
    } 
    return 0; 
} 
