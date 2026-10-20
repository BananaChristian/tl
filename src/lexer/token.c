#include "token.h"
#include "strv.h"
#include <stdio.h>

Token token_new(TType token_type, const char *lexeme, Span span) {
  return (Token){.token_type = token_type,
                 .lexeme = strv_from_range(span.start, span.end, lexeme),
                 .span = span};
}

TType get_token_type(Token *token) { return token->token_type; }

static const char *ttype_string(TType token_type) {
  switch (token_type) {
  case TOK_INTEGER:
    return "INTEGER";
  case TOK_IDENT:
    return "IDENTIFIER";
  case TOK_BIND:
    return "BIND";
  case TOK_MINUS:
    return "MINUS";
  case TOK_PLUS:
    return "PLUS";
  case TOK_SLASH:
    return "SLASH";
  case TOK_COLON:
    return "COLON";
  case TOK_LPAREN:
    return "LPAREN";
  case TOK_RPAREN:
    return "RPAREN";
  case TOK_LBRACE:
    return "LBRACE";
  case TOK_RBRACE:
    return "RBRACE";
  case TOK_ARROW:
    return "ARROW";
  case TOK_ILLEGAL:
    return "ILLEGAL";
  case TOK_END:
    return "END";
  }
}

void print_token(Token token) {
  const char *ttype_str = ttype_string(token.token_type);
  printf("[%s] %.*s [%zu..%zu]\n", ttype_str, (int)token.lexeme.length,
         token.lexeme.data, token.span.start, token.span.end);
}
