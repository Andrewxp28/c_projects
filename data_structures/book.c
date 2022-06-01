#include "book.h"

book_t *create_book(int book_id, char *author, double price) {

    book_t *new_book = NULL;
    new_book = safe_malloc(sizeof(book_t));
    new_book->book_id = book_id;
    new_book->price = price;
    // copying author
    new_book->author = strdup(author);
    return new_book;
}

void free_book(void *ptr) {
    book_t *book = (book_t *)ptr;
    free(book->author);
    free(book);
    book = NULL;
    return;
}

void print_book(void *ptr) {
    book_t *book = (book_t *)ptr;

    printf("Book id: %d\n", book->book_id);
    printf("Author: %s\n", book->author);
    printf("Price: %lf\n", book->price);
}
