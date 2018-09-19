#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef OS_EX3_H
#define OS_EX3_H

#endif //OS_EX3_H

extern int n, max_size;
extern pthread_t consumer, producer;
extern struct Linked_list *buffer;