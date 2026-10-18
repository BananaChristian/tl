#include "span.h"
#include <stddef.h>
Span span_new(size_t start, size_t end) {
  return (Span){.start = start, .end = end};
}

size_t get_span_start(Span *span) { return span->start; }

size_t get_span_end(Span *span) { return span->end; }
