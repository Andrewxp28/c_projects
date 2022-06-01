#ifndef BST_H
#define BST_H

typedef struct node_bst {
  void *data;
  struct node_bst *left, *right;
} node_bst;

/* This binary search tree only store a reference to the data through void
 * *data. The data must be malloc elsewhere. However with the use of custom free
 * functions, the data can be freed through the bst custom functions.*/

// create and mallocs space for new bst_node
node_bst *new_bst_node(void *data, int size);
// default free for freeing data within node and the node itself
void free_bst_node(node_bst *node);
// frees bst node given a custom free function for the data.
void free_bst_node_custom(node_bst *node, void (*custom_free)(void *));
// frees nodes within the tree and tree itself
void free_bst(node_bst *node);
// frees nodes within the tree and tree iteself with a special data and a custom
// free function used by custom_free_bst_node.
void free_bst_custom(node_bst *node,
                     void (*custom_free_bst_node)(node_bst *node,
                                                  void (*custom_free)(void *)),
                     void (*custom_free_func)(void *));
// insert node into tree
node_bst *insert(node_bst *node, void *data, int size,
                 int (*comparator)(const void *, const void *));
// works for ints only
void inorder_print(node_bst *root);
// search tree for data and return that node
node_bst *search(node_bst *node, void *data,
                 int (*comparator)(const void *, const void *));
#endif