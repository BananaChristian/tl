#include "parser.h"
#include "vec.h"

void parser_init(Parser *parser, Vec tokens) {
  parser->tokens = tokens;
  parser->current_pos = 0;
}

void parser_advance(Parser *parser) {
  if (parser->current_pos <= parser->tokens.length) {
    parser->current_pos++;
  }
}

Token current_token(Parser *parser) {
  Token *token_ptr =
      (Token *)vec_access_at(&parser->tokens, parser->current_pos);
  return *token_ptr;
}
