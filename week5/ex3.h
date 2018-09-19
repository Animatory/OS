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


void insert_last(struct Linked_list *list, int value);

struct Linked_list *create_linked_list(int value);

void delete_node(struct Linked_list *list, int value);

int pop_first(struct Linked_list *list);