#include "cli.h"
#include "lexer.h"
#include "token.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *open_file(const char *filename) {
  FILE *file = fopen(filename, "rb");
  if (!file) {
    fprintf(stderr, "Failed to open file %s\n", filename);
    return NULL;
  }

  fseek(file, 0, SEEK_END);

  long file_size = ftell(file);
  if (file_size == -1L) {
    fprintf(stderr, "Something is off with ftell\n");
    fclose(file);
    return NULL;
  }
  rewind(file);

  char *data = (char *)malloc(file_size + 1);
  if (!data) {
    fprintf(stderr, "I dont have error messages but just know the OS has "
                    "refused to give us memory\n");
    fclose(file);
    return NULL;
  }

  size_t items_read = fread(data, sizeof(char), file_size, file);
  if (items_read < (size_t)file_size) {
    fprintf(stderr,
            "Did not read the expected number of bytes: expected %zu but got "
            "%zu\n",
            file_size, items_read);
    fclose(file);
    free(data);
    return NULL;
  }

  data[items_read] = '\0';

  fclose(file);
  return data;
}

int main(int argc, char *argv[]) {
  CliArgs args = parse_cli_args(argc, argv);

  if (!args.filename) {
    return -1;
  }
  char *source_file = open_file(args.filename);

  if (!source_file) {
    return -1;
  }

  Lexer lexer = {0};
  lexer_init(&lexer, source_file);
  Vec tokens = lexer_tokenize(&lexer);
  for (size_t i = 0; i < tokens.length; i++) {
    Token *token_data = (Token *)tokens.data;
    Token token = token_data[i];
    print_token(token);
  }

  free(source_file);
  return 0;
}
