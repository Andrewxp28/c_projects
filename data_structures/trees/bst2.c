#include "bst2.h"

node_bst2 *create_bst2_node(void *data) {

    node_bst2 *new_node = safe_malloc(sizeof(node_bst2));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void free_bst2_node(node_bst2 *node) {
    if (node == NULL) {
        return;
    }
    free(node);
    node = NULL;
    return;
}

void free_bst2_node_custom(node_bst2 *node, void (*custom_free_data)(void *)) {

    if (node == NULL)
        return;
    custom_free_data(node->data);
    free(node);
    node = NULL;
    return;
}

bst_t *create_bst2(void) {
    bst_t *bst = safe_malloc(sizeof(bst_t));
    bst->num_nodes = 0;
    bst->root = NULL;
    return bst;
}

// frees the nodes of the tree recursively
void free_bst2_nodes(node_bst2 *node) {
    if (node == NULL) {
        return;
    }
    free_bst2_nodes(node->left);
    free_bst2_nodes(node->right);
    // free current node
    free_bst2_node(node);
}

void free_bst2_nodes_custom(node_bst2 *node, void (*custom_free)(void *)) {
    if (node == NULL) {
        return;
    }
    free_bst2_nodes_custom(node->left, custom_free);
    free_bst2_nodes_custom(node->right, custom_free);
    // free a node with custom data
    free_bst2_node_custom(node, custom_free);
}

// calls free_bst2_nodes, and frees tree and nodes
void free_bst2(bst_t *bst) {

    free_bst2_nodes(bst->root);
    free(bst);
    bst = NULL;
    return;
}

void free_bst2_custom(bst_t *bst, void (*custom_free_data)(void *)) {

    free_bst2_nodes_custom(bst->root, custom_free_data);
    free(bst);
    bst = NULL;
    return;
}
// recusively looks for correct place in tree
node_bst2 *insert_in_bst2_helper(node_bst2 *node, void *data,
                                 int (*comparator)(const void *,
                                                   const void *)) {

    if (node == NULL) {
        return create_bst2_node(data);
    }
    // find correct spot for data
    if (comparator(data, node->data) < 0) {
        // data is less than current node's data, go left
        node->left = insert_in_bst2_helper(node->left, data, comparator);
    } else if (comparator(data, node->data) > 0) {
        // data is greater than current node's data, go right
        node->right = insert_in_bst2_helper(node->right, data, comparator);
    }
    // we do not put equal/duplicate data into tree. (when comparator(data,
    // node->data) == 0)
    return node;
}

void insert_in_bst2(bst_t *bst, void *data,
                    int (*comparator)(const void *, const void *)) {

    bst->root = insert_node_in_bst2(bst->root, data, comparator);
    return;
}

node_bst2 *search_bst2_helper(node_bst2 *node, void *data,
                              int (*comparator)(const void *, const void *)) {

    if (node == NULL) {
        return node;
    }
    if (comparator(data, node->data) == 0) {
        // found node with desired data
        return node;
    }
    if (comparator(data, node->data) < 0) {
        // desired data is less than current node's data
        return search_bst2_helper(node->left, data, comparator);
    }
    // desired data is larger than current node's data
    return search_bst2_helper(node->right, data, comparator);
}

node_bst2 *search_bst2(bst_t *bst, void *data,
                       int (*comparator)(const void *, const void *)) {

    node_bst2 *searched_node = NULL;
    searched_node = search_bst2_helper(bst->root, data, comparator);
    return searched_node;
}

// returns the next min value given the node (given a non-empty tree)
node_bst2 *min_value(node_bst2 *node,
                     int (*comparator)(const void *, const void *)) {

    node_bst2 *curr = node;

    while (curr->left != NULL) {
        curr = curr->left;
    }

    return curr;
}
// find the inorder successor of node within the tree made by root
node_bst2 *in_order_successor(node_bst2 *root, node_bst2 *node,
                              int (*comparator)(const void *, const void *)) {

    // if right subtree of node is not NULL, then inorder successor lies there.
    if (node->right != NULL) {
        return min_value(node->right, comparator);
    }
    node_bst2 *successor = NULL;
    node_bst2 *curr_node = root;
    // start from root and go down the tree to find inorder successor
    while (curr_node != NULL) {

        if (comparator(node->data, curr_node->data) > 0) {
            curr_node = curr_node->right;
        } else if (comparator(node->data, curr_node->data) < 0) {
            successor = curr_node;
            curr_node = curr_node->left;
        } else {
            break;
        }
    }
    return successor;
}

// need a delete function
node_bst2 *delete_node_bst2(node_bst2 *root, void *data,
                            int (*comparator)(const void *, const void *)) {

    return root;
}