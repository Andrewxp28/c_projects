#include "ll.h"

node_ll *create_node_ll(void *data, unsigned long size) {

    node_ll *new_node = safe_malloc(sizeof(*new_node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

linked_list_t *create_linked_list(int element_size) {

    linked_list_t *list = NULL;
    list = safe_malloc(sizeof(linked_list_t));
    list->head = NULL;
    list->length = 0;
    list->element_size = element_size;
    return list;
}

void free_node_ll(node_ll *node) {

    if (node == NULL)
        return;
    free(node);
    node = NULL;
    return;
}

void free_linked_list(linked_list_t *list) {

    node_ll *current = list->head;
    node_ll *temp = NULL;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free_node_ll(temp);
    }
    free(list);
    list = NULL;
    return;
}

void free_node_ll_custom(node_ll *node, void (*custom_free_data)(void *)) {

    if (node == NULL)
        return;
    custom_free_data(node->data);
    free(node);
    node = NULL;
    return;
}

void free_linked_list_custom(linked_list_t *list,
                             void (*custom_free_data)(void *)) {

    node_ll *current = list->head;
    node_ll *temp = NULL;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free_node_ll_custom(temp, custom_free_data);
    }
    free(list);
    list = NULL;
    return;
}

void insert_at_head(linked_list_t *list, void *data) {
    // checking if this is the first node
    if (list->head == NULL) {
        node_ll *new_head = NULL;
        new_head = create_node_ll(data, list->element_size);
        list->head = new_head;
        list->length = list->length + 1;
        return;
    }

    node_ll *new_node = create_node_ll(data, list->element_size);
    new_node->next = list->head;
    list->head = new_node;
    list->length = list->length + 1;
    return;
}

void print_ll_int(linked_list_t *list) {
    node_ll *current = list->head;

    while (current != NULL) {
        printf("%d -> ", *(int *)(current->data));
        current = current->next;
    }
    printf("\n");
    return;
}

void print_ll(linked_list_t *list, void (*print_data)(void *)) {

    node_ll *current = list->head;

    while (current != NULL) {
        print_data(current->data);
        current = current->next;
    }
    printf("\n");
    return;
}