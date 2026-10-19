#ifndef TOKEN_H
#define TOKEN_H

#include "span.h"
#include "strv.h"
#include <stddef.h>

typedef enum {
  TOK_BIND,   //:=
  TOK_PLUS,   // +
  TOK_MINUS,  // -
  TOK_SLASH,  // /
  TOK_COLON,  // :
  TOK_LPAREN, //(
  TOK_RPAREN, //)
  TOK_LBRACE, //{
  TOK_RBRACE, //}
  TOK_ARROW,  //->
  TOK_IDENT,
  TOK_ILLEGAL,
  TOK_END,
} TType;

typedef struct {
  TType token_type;
  Strv lexeme;
  Span span;
} Token;

Token token_new(TType token_type, const char *lexeme, Span span);
TType get_token_type(Token *token);

#endif // !TOKEN_H
