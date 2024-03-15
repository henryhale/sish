#include "shell.h"
#include <stdbool.h>  /* true */
#include <stdio.h>    /* printf(), perror */
#include <stdlib.h>   /* exit(), EXIT_SUCCESS, EXIT_FAILURE */
#include <string.h>   /* strlen(), strcmp() */
#include <sys/wait.h> /* wait() */
#include <unistd.h>   /* fork(), execvpe(), environ */

extern char **environ;

int main(int argc, char *argv[]) {
  printf("Hello World!\n");

  struct shell_state* state = malloc(sizeof(struct shell_state));

  init_shell(argc, argv, state);

  while (true) {
    state->input = prompt(state->name);
    /* printf("input: %s", state->input); */
    if (strlen(state->input) < 2)
      continue;

    tokenize(state->input, state->args, " \n");
    /* printf("command: %s, %s\n", state->args[0], state->args[1]); */

    if (strcmp(*state->args, "exit") == 0) {
      break;
    }

    pid_t pid;
    pid = fork();

    if (pid == -1) {
      perror("fork");
      break;
    } else if (pid == 0) {
      /* printf("child process: running, %jd\n", (intmax_t) getpid()); */
      if (execvp(state->args[0], state->args) == -1)
        perror(state->name);
      /* printf("child process: exiting.\n"); */
      exit(EXIT_SUCCESS);
    } else {
      /* sleep(1); */
      wait(NULL);
      /* printf("main process: exiting, from child: %jd\n", (intmax_t)pid); */
    }
  }

  clean_up(state);

  return EXIT_SUCCESS;
}
