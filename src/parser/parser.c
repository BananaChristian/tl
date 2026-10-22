#include "parser.h"
#include "token.h"
#include "vec.h"
#include <stdio.h>

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

void expect_token(Parser *parser, TType expected_token) {
  Token curr_token = current_token(parser);
  if (expected_token == curr_token.token_type) {
    parser_advance(parser);
  } else {
    fprintf(stderr, "Unexpected token\n");
  }
}
