#include "utils.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void *safe_malloc(size_t size) {
  void *ptr = malloc(size);
  if (ptr == NULL) {
    fprintf(stderr, "Malloc failure\n");
    exit(EXIT_FAILURE);
  }
  return ptr;
}

int int_comparator(const void *num1, const void *num2) {
  return (*(int *)num1 - *(int *)num2);
}