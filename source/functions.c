#include "shell.h"
#include <stdio.h>  /* printf(), getline(), stdin, fflush(), NULL */
#include <stdlib.h> /* free() */
#include <string.h> /* strtok() */
#include <unistd.h> /* getpid() */

/* ANSI color codes */
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define WHITE "\033[0;37m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

/* prompt a user to enter command */
char *prompt(char *const name) {
  char *input = NULL;
  static size_t size = MAX_INPUT;
  printf("%s[%s", RED, RESET);
  printf("%s%s%s", GREEN, name, RESET);
  printf("%s-%s", MAGENTA, RESET);
  printf("%s%u%s", CYAN, getpid(), RESET);
  printf("%s]", RED);
  printf(" $%s%s ", RESET, WHITE);
  fflush(stdin);
  int status = getline(&input, &size, stdin);
  if (status < 0) {
    free(input);
    input = NULL;
  }
  return input;
}

/* split the input string into a list of arguments */
void tokenize(char *const input, char *tokens[], const char delimiters[]) {
  int i = 0;
  char *tkn = strtok(input, delimiters);
  while (tkn != NULL) {
    *(tokens + i) = tkn;
    tkn = strtok(NULL, delimiters);
    i++;
  }
  *(tokens + i) = NULL;
}
