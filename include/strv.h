#ifndef STRV_H
#define STRV_H

#include <stddef.h>
#include <string.h>

// This is the string view type
typedef struct {
  const char *data;
  size_t length;
} Strv;

Strv strv_from_cstr(const char *str);
Strv strv_from_pos(size_t pos, const char *str);
Strv strv_from_range(size_t start, size_t end, const char *str);
char strv_char_at(Strv *view, size_t index);

#endif // !STRV_H
