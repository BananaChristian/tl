#include "vec.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Vec vec_init(size_t element_size) {
  return (Vec){.data = NULL,
               .element_size = element_size,
               .capacity = INIT_VEC_CAP,
               .length = 0};
}

static void vec_append_unchecked(Vec *vec, void *element) {
  if (vec->length >= vec->capacity) {
    size_t new_capacity = vec->capacity * 2;
    void *temp_data = realloc(vec->data, new_capacity * vec->element_size);
    if (!temp_data) {
      fprintf(stderr, "Failed to get new memory\n");
      return;
    }
    vec->capacity = new_capacity;
    vec->data = temp_data;
    size_t offset = vec->length * vec->element_size;
    memcpy((char *)(vec->data) + offset, element, vec->element_size);
    vec->length++;
  } else {
    size_t offset = vec->length * vec->element_size;
    memcpy((char *)(vec->data) + offset, element, vec->element_size);
    vec->length++;
  }
}

void vec_append(Vec *vec, void *element) {
  if (!vec->data) {
    void *temp_data = malloc(vec->capacity * vec->element_size);
    if (!temp_data) {
      fprintf(stderr, "Failed to get memory from malloc\n");
      return;
    } else {
      vec->data = temp_data;
      vec_append_unchecked(vec, element);
    }
  } else {
    vec_append_unchecked(vec, element);
  }
}

void *vec_access_at(Vec *vec, size_t index) {
  if (index >= vec->length) {
    fprintf(stderr, "Index %zu\n is out of bounds for length %zu\n", index,
            vec->length);
    return NULL;
  }

  char *element_ptr = (char *)(vec->data) + (index * vec->element_size);
  return (void *)element_ptr;
}
