#include "lexer.h"
#include <stdio.h>
int main() {
  const char *src = "/+-:=";
  Lexer lexer = {0};
  lexer_init(&lexer, src);
  Vec tokens = lexer_tokenize(&lexer);

  printf("The vector has length: %zu\n", tokens.length);
  return 0;
}
