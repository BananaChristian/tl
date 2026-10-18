#ifndef LEXER_H
#define LEXER_H

#include "strv.h"
#include "vec.h"
#include <stddef.h>

typedef struct {
  size_t pos;
  Strv src;
  size_t line;
  size_t col;
} Lexer;

void lexer_init(Lexer *lexer, const char *src);
Vec lexer_tokenize(Lexer *lexer);

#endif // !LEXER_H
