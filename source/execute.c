#include "shell.h"
#include <stdio.h>    /* perror() */
#include <stdlib.h>   /* exit(), EXIT_SUCCESS, EXIT_FAILURE */
#include <sys/wait.h> /* wait() */
#include <unistd.h>   /* fork(), execvp() */

void exec_command(char **args, char *const name) {
    pid_t pid;
    pid = fork();

    if (pid == -1) {
      perror("fork");
    } else if (pid == 0) {
      if (execvp(args[0], args) == -1) {
        perror(name);
      }
      exit(EXIT_FAILURE);
    } else {
      wait(NULL);
    }
}