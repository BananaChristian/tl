#ifndef ARENA_H
#define ARENA_H

#include <stddef.h>

typedef struct Chunk Chunk;

struct Chunk {
  size_t capacity;
  size_t used;
  void *base;
  void *cursor;
  Chunk *next;
};

typedef struct {
  Chunk *chunks;
} Arena;

void arena_init(Arena *arena);
void *arena_alloc(Arena *arena, size_t object_size);
void arena_destroy(Arena *arena);

#endif // !ARENA_H
