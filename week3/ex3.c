#include <stdio.h>
#include <stdlib.h>

struct Linked_list {
    int data;
    struct Linked_list *prev;
    struct Linked_list *next;
};

struct Linked_list* create_linked_list(int value){
    struct Linked_list *list = malloc(sizeof(struct Linked_list));
    list->data = value;
    list->prev = NULL;
    list->next = NULL;
    return list;
}

void insert_first(struct Linked_list *list, int value) {
    struct Linked_list *new = create_linked_list(value);
    while (list->prev != NULL) {
        list = list->prev;
    }
    new->next = list;
    list->prev = new;
};

void insert_last(struct Linked_list *list, int value) {
    struct Linked_list *new = create_linked_list(value);

    while (list->next != NULL) {
        list = list->next;
    }
    new->prev = list;
    list->next = new;
};

void insert_before(struct Linked_list *list, int value) {
    struct Linked_list *new = create_linked_list(value);

    if (list->prev != NULL){
        new->prev = list->prev;
        list->prev->next = new;
    }
    list->prev = new;
    new->next = list;
};

void insert_after(struct Linked_list *list, int value) {
    struct Linked_list *new = create_linked_list(value);

    if (list->next != NULL){
        new->next = list->next;
        list->next->prev = new;
    }
    list->next = new;
    new->prev = list;
};

void delete_node(struct Linked_list *list, int value) {
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

void print_list(struct Linked_list *list) {
    while (list->prev != NULL) {
        list = list->prev;
    }

    while (list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

int main() {
    int arr[] = {3, 0, 6, 23, 86,1, -34, 8, 12, -9};
    int i, n = sizeof(arr)/sizeof(arr[0]);
    struct Linked_list* list = create_linked_list(1);
    for (i = 0; i < n; i++) {
        insert_last(list, arr[i]);
    }
    print_list(list);
    delete_node(list, 6);
    print_list(list);
    return 0;
}
