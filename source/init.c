#include "shell.h"
#include <stdio.h> /* NULL */
#include <stdlib.h>

/* initialize the state of the shell */
void init_shell(int argc, char *argv[], struct shell_state *const state) {
  if (argc > 1 && argv[1] != NULL) {
    state->name = argv[1];
  } else {
    state->name = "sish";
  }
}

/* clean up resources */
void clean_up(struct shell_state *const state) {
  state->name = NULL;
  state->input = NULL;
  free(state);
}
