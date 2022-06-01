#ifndef BST2_H
#define BST2_H

#include "../utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structs
typedef struct node_bst2 {
    void *data;
    struct node_bst2 *left, *right;
} node_bst2;

typedef struct bst_t {
    struct node_bst2 *root;
    int num_nodes;
} bst_t;

// functions
// creates a node for a bst
node_bst2 *create_bst2_node(void *data);
// frees a bst node
void free_bst2_node(node_bst2 *node);
// free a bst node along with custom data.
void free_bst2_node_custom(node_bst2 *node, void (*custom_free_data)(void *));
// allocates space for a bst with nodes hol
bst_t *create_bst2(void);
// might be a "private function"
// void free_bst2_nodes(node_bst2 *node);
// might be a "private function"
// void free_bst2_nodes_custom(node_bst2 *node, void (*custom_free)(void *));
// frees a bst and the entire tree of nodes
void free_bst2(bst_t *bst);
// frees a bst and the entire tree of nodes containing custom data
void free_bst2_custom(bst_t *bst, void (*custom_free_data)(void *));
//
void insert_in_bst2(bst_t *bst, void *data,
                    int (*comparator)(const void *, const void *));
//
node_bst2 *search_bst2(bst_t *bst, void *data,
                       int (*comparator)(const void *, const void *));

#endif