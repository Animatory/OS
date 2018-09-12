#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


int main() {
    for (int i = 0; i < 5; ++i) {
        fork();
        sleep(5);
    }
}
