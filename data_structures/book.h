#ifndef BOOK_H
#define BOOK_H

#include "utils/utils.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structs
typedef struct book_t {
    int book_id;
    char *author;
    double price;
} book_t;

// functions
book_t *create_book(int book_id, char *author, double price);
void free_book(void *ptr);
void print_book(void *ptr);
#endif