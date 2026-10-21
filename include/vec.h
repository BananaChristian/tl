#ifndef VEC_H
#define VEC_H

#include <stddef.h>
#define INIT_VEC_CAP 10

typedef struct {
  void *data;
  size_t element_size;
  size_t capacity;
  size_t length;
} Vec;

Vec vec_init(size_t element_size);
void vec_append(Vec *vec, void *element);
void *vec_access_at(Vec *vec, size_t index);

#endif // !VEC_H
