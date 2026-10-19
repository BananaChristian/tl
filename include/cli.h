#ifndef CLI_H
#define CLI_H

typedef struct {
  char *filename;
  char *object_file;
} CliArgs;

void print_help();
CliArgs parse_cli_args(int argc, char *argv[]);

#endif // !CLI_H
