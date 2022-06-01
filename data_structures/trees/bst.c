#include "bst.h"
#include "../utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node_bst *new_bst_node(void *data, int size) {
  node_bst *new_node = safe_malloc(sizeof(*new_node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
};

void free_bst_node(node_bst *node) {
  free(node);
  node = NULL;
  return;
}

void free_bst_node_custom(node_bst *node, void (*custom_free)(void *)) {
  custom_free(node->data);
  free(node);
  node = NULL;
  return;
}

void free_bst(node_bst *node) {
  if (node == NULL) {
    return;
  }
  free_bst(node->left);
  free_bst(node->right);

  free_bst_node(node);
  return;
}

void free_bst_custom(node_bst *node,
                     void (*custom_free_bst_node)(node_bst *node,
                                                  void (*custom_free)(void *)),
                     void (*custom_free_func)(void *)) {

  if (node == NULL) {
    return;
  }
  free_bst_custom(node->left, custom_free_bst_node, custom_free_func);
  free_bst_custom(node->right, custom_free_bst_node, custom_free_func);

  // free node and data
  custom_free_bst_node(node, custom_free_func);
  return;
}

node_bst *insert(node_bst *node, void *data, int size,
                 int (*comparator)(const void *, const void *)) {
  if (node == NULL) {
    return new_bst_node(data, size);
  }
  // data is less than this node's data so go left
  if (comparator(data, node->data) < 0) {
    node->left = insert(node->left, data, size, comparator);
  } else {
    node->right = insert(node->right, data, size, comparator);
  }

  return node;
}

void inorder_print(node_bst *root) {

  if (root != NULL) {
    inorder_print(root->left);
    printf("data -> %d\n", *(int *)(root->data));
    inorder_print(root->right);
  }
}

node_bst *search(node_bst *node, void *data,
                 int (*comparator)(const void *, const void *)) {

  if (node == NULL)
    return node;
  if (comparator(data, node->data) == 0) {
    // found key
    return node;
  }
  if (comparator(data, node->data) > 0) {
    // desired data is larger than node->data
    return search(node->right, data, comparator);
  }
  // desired data is smaller than node->data
  return search(node->left, data, comparator);
}