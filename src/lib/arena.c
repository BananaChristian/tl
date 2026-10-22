#include "arena.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void arena_init(Arena *arena) {
  Chunk *chunks = (Chunk *)malloc(sizeof(Chunk));
  if (!chunks) {
    fprintf(stderr, "Failed to get memory from OS to allocate chunks\n");
    return;
  }
  // Initialize the first chunk
  size_t capacity = 4096;
  void *base = malloc(capacity);
  if (!base) {
    fprintf(stderr, "Failed to get memory from OS to allocate chunks\n");
    free(chunks);
    return;
  }

  arena->chunks = chunks;

  arena->chunks->capacity = capacity;
  arena->chunks->base = base;
  arena->chunks->cursor = arena->chunks->base;
  arena->chunks->used = 0;
  arena->chunks->next = NULL;
}

void *arena_alloc(Arena *arena, size_t object_size) {}

void arena_destroy(Arena *arena) {
  while (arena->chunks) {
    Chunk *next_chunk = arena->chunks->next;
    free(arena->chunks->base);
    free(arena->chunks);
    arena->chunks = next_chunk;
  }
}
