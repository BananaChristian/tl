#include "token.h"
#include "strv.h"

Token token_new(TType token_type, const char *lexeme, Span span) {
  return (Token){.token_type = token_type,
                 .lexeme = strv_from_range(span.start, span.end, lexeme),
                 .span = span};
}

TType get_token_type(Token *token) { return token->token_type; }
