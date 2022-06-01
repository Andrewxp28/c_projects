#include "book.h"
#include "lists/ll.h"
#include "person.h"
#include "trees/bst.h"
#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {
    /*
      // currently works 22/04/22
      // testing for person struct for bst tree
      char name1[] = "Andrew";
      char name2[] = "Ando";
      char name3[] = "Sarah";
      // char name4[] = "Anthony";
      person_t *andrew = make_person(40, name1);
      person_t *ando = make_person(10, name2);
      person_t *sarah = make_person(25, name3);
      person_t *anthony = make_person(9, "Anthony");
      person_t *stella = make_person(69, "Stella");
      person_t *jwoo = make_person(30, "jwoo");

      node_bst *root = new_bst_node(andrew, sizeof(andrew));
      root = insert(root, ando, sizeof(ando), person_comparator);
      root = insert(root, sarah, sizeof(sarah), person_comparator);
      root = insert(root, anthony, sizeof(anthony), person_comparator);
      root = insert(root, stella, sizeof(stella), person_comparator);
      root = insert(root, jwoo, sizeof(jwoo), person_comparator);
      // inorder_person_print(root);
      // free_bst_person(root);
      // searching for a person inside the tree
      node_bst *searched_node = NULL;
      searched_node = search(root, jwoo, person_comparator);
      inorder_person_print(root);
      if (searched_node != NULL) {
          // found it
          printf("Found them! Person id: %d, name: %s\n",
                 ((person_t *)(searched_node->data))->id,
                 ((person_t *)(searched_node->data))->name);
      } else {
          printf("Person not found in tree\n");
      }
      free_bst_custom(root, free_bst_node_custom, free_person);
      */
    /*
    // currently works 22/04/22
    // testing for ints for bst tree
    // int arr_length = 10;
    int arr[10] = {20, 35, 40, 92, 69, 15, 10, 37, 95, 74};
    node_bst *root = new_bst_node(&arr[0], sizeof(*arr));
    for (int i = 1; i < 10; i++) {
        root = insert(root, &arr[i], sizeof(*arr), int_comparator);
    }

    inorder_print(root);
    node_bst *searched_node = NULL;
    searched_node = search(root, &arr[4], int_comparator);
    if (searched_node != NULL) {
        printf("found it: %d\n", *((int *)(searched_node->data)));
    } else {
        printf("number not found in tree\n");
    }
    free_bst(root);
    */
    /*
     Linked list testing
        works 24/04/22
    int arr[] = {25, 43, 69, 32, 8, 20, 22, 90, 12};
    int length = 9;
    linked_list_t *list = NULL;
    list = create_linked_list(sizeof(int));
    for (int i = 0; i < length; i++) {
        insert_at_head(list, &arr[i]);
    }
    print_ll_int(list);
    free_linked_list(list);
    */
    /*
    book_t *book1 = create_book(1, "Andrew Pham", 69.69);
    book_t *book2 = create_book(50, "Anthony Lui", 29.99);
    book_t *book3 = create_book(20, "Sarah Khoo", 19.99);
    printf("printing list below:\n");
    linked_list_t *book_list = create_linked_list(sizeof(book1));
    insert_at_head(book_list, book1);
    insert_at_head(book_list, book2);
    insert_at_head(book_list, book3);
    print_ll(book_list, print_book);
    free_linked_list_custom(book_list, free_book);
     */
    return 0;
}