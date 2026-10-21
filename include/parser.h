#ifndef PARSER_H
#define PARSER_H

#include "token.h"
#include "vec.h"
#include <stddef.h>

typedef struct {
  size_t current_pos;
  Vec tokens;
} Parser;

void parser_init(Parser *parser, Vec tokens);
void parser_advance(Parser *parser);
Token current_token(Parser *parser);

#endif // !PARSER_H
