#include "ex3.h"
#define OS_EX3_H

int n, max_size;
pthread_t consumer, producer;
struct Linked_list *buffer;

void insert_last(struct Linked_list *list, int value);

struct Linked_list *create_linked_list(int value);

void delete_node(struct Linked_list *list, int value);

int pop_first(struct Linked_list *list);

void *consume(void *tid) {
    if (n <= 1)
        pthread_join(producer, NULL);
    int value = pop_first(buffer);
    n--;
    printf("Greetings from consumer. Current value: %d\n", value);
    pthread_exit(NULL);
}

void *produce(void *tid) {
    if (n >= max_size)
        pthread_join(consumer, NULL);
    insert_last(buffer, (int) tid);
    n++;
    pthread_exit(NULL);
}


int main(int argc, char *argv[]) {
    n = 1, max_size = 10;
    int status1, status2, i = 1;
    buffer = create_linked_list(0);
    while (1) {
        status1 = pthread_create(&producer, NULL, produce, (void *) i);
        status2 = pthread_create(&consumer, NULL, consume, (void *) i);
        i++;
        sleep(60);

        if (status1 != 0 || status2 != 0) {
            printf("Oops. pthread create returned error code %d\n", (status1 != 0) ? status1 : status2);
            exit(-1);
        }
    }
}

struct Linked_list {
    int data;
    struct Linked_list *prev;
    struct Linked_list *next;
};

struct Linked_list *create_linked_list(int value) {
    struct Linked_list *list = malloc(sizeof(struct Linked_list));
    list->data = value;
    list->prev = NULL;
    list->next = NULL;
    return list;
}

int pop_first(struct Linked_list *list) {
    int value = list->data;
    delete_node(list, value);
    return value;
};

void insert_last(struct Linked_list *list, int value) {
    struct Linked_list *new = create_linked_list(value);
    while (list->next != NULL) {
        list = list->next;
    }
    new->prev = list;
    list->next = new;
};

void delete_node(struct Linked_list *list, int value) {
    if (list->data == value) {
        if (list->next != NULL) {
            struct Linked_list *next = list->next;
            list->data = next->data;
            if (next->next != NULL) {
                next->next->prev = list;
            }
            list->next = next->next;
            free(next);
        } else if (list->prev != NULL) {
            struct Linked_list *prev = list->prev;
            list->data = prev->data;
            if (prev->prev != NULL) {
                prev->prev->next = list;
            }
            list->prev = prev->prev;
            free(prev);
        } else {
            free(list);
        }
        return;
    }
    while (list->prev != NULL) {
        list = list->prev;
    }

    while (list != NULL) {
        if (list->data == value) {
            list->prev->next = list->next;
            list->next->prev = list->prev;
            free(list);
            return;
        }
        list = list->next;
    }
};
