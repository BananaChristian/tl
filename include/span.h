#ifndef SPAN_H
#define SPAN_H

#include <stddef.h>

typedef struct {
  size_t start;
  size_t end;
} Span;

Span span_new(size_t start, size_t end);
size_t get_span_start(Span *span);
size_t get_span_end(Span *span);

#endif // !SPAN_H
