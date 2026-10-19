#include "strv.h"
#include <stddef.h>
#include <string.h>

Strv strv_from_cstr(const char *str) {
  return (Strv){.data = str, .length = strlen(str)};
}

Strv strv_from_pos(size_t pos, const char *str) {
  const char *new_str = str + pos;
  return (Strv){.data = new_str, .length = strlen(new_str)};
}

Strv strv_from_range(size_t start, size_t end, const char *str) {
  const char *new_str = str + start;
  size_t length = end - start;
  return (Strv){
      .data = new_str,
      .length = length,
  };
}

char strv_char_at(Strv *view, size_t index) {
  if (index <= view->length) {
    return view->data[index];
  } else {
    return '\0';
  }
}
