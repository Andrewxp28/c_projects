#ifndef LL_H
#define LL_H

#include "../utils/utils.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// structs
typedef struct node_ll {
    void *data;
    struct node_ll *next;
} node_ll;

typedef struct linked_list_t {
    struct node_ll *head;
    int length;
    int element_size;
} linked_list_t;

// functions
// creates a node for the linked list
node_ll *create_node_ll(void *data, unsigned long size);
// creates a list for data size of element_size
linked_list_t *create_linked_list(int element_size);
// free a node of linked list
void free_node_ll(node_ll *node);
// frees a linked list
void free_linked_list(linked_list_t *list);
// frees custom data within node and node itself
void free_node_ll_custom(node_ll *node, void (*custom_free_data)(void *));
// frees a linked list containing custom data
void free_linked_list_custom(linked_list_t *list,
                             void (*custom_free_data)(void *));
// creates a new node with data and inserts it at head of list
void insert_at_head(linked_list_t *list, void *data);
// prints a linked list for int
void print_ll_int(linked_list_t *list);
// prints a linked list using custom print_data function
void print_ll(linked_list_t *list, void (*print_data)(void *));
#endif