#include <stddef.h>
#include <stdlib.h>

#ifndef UTILS_H
#define UTILS_H

void *safe_malloc(size_t size);

int int_comparator(const void *num1, const void *num2);
#endif