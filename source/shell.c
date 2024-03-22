#include "shell.h"
#include <stdbool.h>  /* true */
#include <stdio.h>    /* printf()*/
#include <string.h>   /* strlen(), strcmp() */
#include <stdlib.h>   /* malloc() */

int main(int argc, char *argv[]) {
  printf("Hello World!\n");

  struct shell_state* state = malloc(sizeof(struct shell_state));

  init_shell(argc, argv, state);

  while (true) {
    state->input = prompt(state->name);
    if (strlen(state->input) == 1) {
      continue;
    }

    tokenize(state->input, state->args, " \n");

    if (strcmp(*state->args, "exit") == 0) {
      break;
    }

    exec_command(state->args, state->name);
  }

  clean_up(state);

  return EXIT_SUCCESS;
}
