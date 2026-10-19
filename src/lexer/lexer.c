#include "lexer.h"
#include "span.h"
#include "strv.h"
#include "token.h"
#include "vec.h"
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>

void lexer_init(Lexer *lexer, const char *src) {
  lexer->pos = 0;
  lexer->src = strv_from_cstr(src);
}

static char current_char(Lexer *lexer) {
  return strv_char_at(&lexer->src, lexer->pos);
}

static char peek_char(Lexer *lexer) {
  return strv_char_at(&lexer->src, lexer->pos + 1);
}

static void advance(Lexer *lexer) {
  if (lexer->pos <= lexer->src.length) {
    lexer->pos++;
  }
}

static void skip_comments(Lexer *lexer) {
  if (current_char(lexer) == '/' && peek_char(lexer) == '/') {
    while (1) {
      advance(lexer);
      bool end_comment =
          current_char(lexer) == '\n' || current_char(lexer) == '\0';
      if (end_comment) {
        break;
      }
    }
  }
}

static void skip_whitespace(Lexer *lexer) {
  while (isspace(current_char(lexer))) {
    advance(lexer);
  }
}

static void skip_whitespace_and_comments(Lexer *lexer) {
  while (1) {
    skip_whitespace(lexer);
    if (current_char(lexer) == '/' && peek_char(lexer) == '/') {
      skip_comments(lexer);
      continue;
    }
    break;
  }
}

static Token read_identifier(Lexer *lexer) {
  size_t start = lexer->pos;
  while (isalpha(current_char(lexer)) || current_char(lexer) == '_') {
    advance(lexer);
  }
  return (Token){.token_type = TOK_IDENT,
                 .lexeme = strv_from_range(start, lexer->pos, lexer->src.data),
                 .span = span_new(start, lexer->pos)};
}

static Token next_token(Lexer *lexer) {
  skip_whitespace_and_comments(lexer);
  char c = current_char(lexer);
  size_t start = lexer->pos;

  if (isalnum(c) || c == '_') {
    return read_identifier(lexer);
  }

  switch (c) {
  case '+': {
    advance(lexer); // Consume the +
    return token_new(TOK_PLUS, lexer->src.data, span_new(start, lexer->pos));
  }
  case '-': {
    advance(lexer);
    if (current_char(lexer) == '>') {
      return token_new(TOK_ARROW, lexer->src.data, span_new(start, lexer->pos));
    }
    return token_new(TOK_MINUS, lexer->src.data, span_new(start, lexer->pos));
  }
  case '/': {
    advance(lexer);
    return token_new(TOK_SLASH, lexer->src.data, span_new(start, lexer->pos));
  }
  case ':': {
    advance(lexer);
    if (current_char(lexer) == '=') {
      advance(lexer);
      return token_new(TOK_BIND, lexer->src.data, span_new(start, lexer->pos));
    }
    return token_new(TOK_COLON, lexer->src.data, span_new(start, lexer->pos));
  }
  case '{': {
    advance(lexer);
    return token_new(TOK_LBRACE, lexer->src.data, span_new(start, lexer->pos));
  }
  case '}': {
    advance(lexer);
    return token_new(TOK_RBRACE, lexer->src.data, span_new(start, lexer->pos));
  }
  case '(': {
    advance(lexer);
    return token_new(TOK_LPAREN, lexer->src.data, span_new(start, lexer->pos));
  }
  case ')': {
    advance(lexer);
    return token_new(TOK_RPAREN, lexer->src.data, span_new(start, lexer->pos));
  }
  case '\0': {
    return token_new(TOK_END, lexer->src.data, span_new(start, lexer->pos));
  }
  default: {
    advance(lexer);
    return token_new(TOK_ILLEGAL, lexer->src.data, span_new(start, lexer->pos));
  }
  }
}

Vec lexer_tokenize(Lexer *lexer) {
  Vec tokens = vec_init(sizeof(Token));
  while (1) {
    Token token = next_token(lexer);
    vec_append(&tokens, &token);
    if (get_token_type(&token) == TOK_END) {
      break;
    }
  }
  return tokens;
}
