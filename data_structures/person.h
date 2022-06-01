

#include "trees/bst.h"
#include "utils/utils.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PERSON_H
#define PERSON_H

typedef struct person_t {
    int id;
    char *name;

} person_t;

person_t *make_person(int id, char *name);
void free_person(void *ptr);
int person_comparator(const void *p1, const void *p2);
void inorder_person_print(node_bst *root);
void free_node_person(node_bst *node);
void free_bst_person(node_bst *node);

#endif