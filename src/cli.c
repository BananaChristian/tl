#include "cli.h"
#include <stdio.h>
#include <string.h>

void print_help() {
  printf("Tiny Language compiler\n");
  printf("Version 1.0\n");
}

CliArgs parse_cli_args(int argc, char *argv[]) {
  CliArgs args = {0};

  if (argc < 2) {
    fprintf(stderr, "Invalide number of arguments usage: tl <file.tl>\n");
    print_help();
  }

  for (int i = 1; i < argc; i++) {
    char *arg = argv[i];
    if (strcmp(arg, "--help") == 0 || strcmp(arg, "-h") == 0) {
      print_help();
      break;
    } else if (arg[0] == '-') {
      fprintf(stderr, "Unknown compiler flag %s\n", arg);
      print_help();
      break;
    } else {
      args.filename = arg;
    }
  }

  return args;
}
