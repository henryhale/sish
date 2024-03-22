#include "shell.h"
#include <stdio.h>  /* printf(), getline(), stdin, fflush(), NULL */
#include <stdlib.h> /* EXIT_SUCCESS, EXIT_FAILURE */
#include <unistd.h> /* getpid() */
#include <string.h>

/* ANSI color codes */
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define WHITE "\033[0;37m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"

/* prompt a user to enter command */
char *prompt(char *const name) {
  char *input = NULL;
  static size_t size = MAX_INPUT;
  int len = 0;

  printf("%s[%s", RED, RESET);
  printf("%s%s%s", GREEN, name, RESET);
  printf("%s-%s", MAGENTA, RESET);
  printf("%s%u%s", CYAN, getpid(), RESET);
  printf("%s] $%s%s ", RED, RESET, WHITE);
  
  fflush(stdout);
  
  fflush(stdin);

  if (getline(&input, &size, stdin) == -1) {
    // incase of ctrl+d - stop
    if (feof(stdin)) {
      exit(EXIT_SUCCESS);
    } else {
      perror("readline");
      exit(EXIT_FAILURE);
    }
  }

  // remove newline if present
  len = strlen(input);
  if (input[len - 1] == '\n') {
    input[len - 1] = '\0';
  }

  return input;
}