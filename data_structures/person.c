#include "person.h"

person_t *make_person(int id, char *name) {

    person_t *new_person = safe_malloc(sizeof(*new_person));
    new_person->id = id;
    // using strdup to store string
    new_person->name = strdup(name);

    return new_person;
}

void free_person(void *ptr) {

    free(((person_t *)ptr)->name);
    free(ptr);
    ptr = NULL;
    return;
}

int person_comparator(const void *p1, const void *p2) {
    return (((person_t *)p1)->id - ((person_t *)p2)->id);
}

void inorder_person_print(node_bst *root) {
    if (root != NULL) {
        inorder_person_print(root->left);
        person_t *person = NULL;
        person = (person_t *)(root->data);
        printf("Person id: %d, name: %s\n", person->id, person->name);
        inorder_person_print(root->right);
    }
}

void free_node_person(node_bst *node) {
    free_person((person_t *)(node->data));
    free(node);
    node = NULL;
    return;
}

void free_bst_person(node_bst *node) {

    if (node == NULL) {
        return;
    }
    free_bst_person(node->left);
    free_bst_person(node->right);

    // free node and data
    free_node_person(node);
    return;
}