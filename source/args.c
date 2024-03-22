#include "shell.h"
#include <stdio.h>
#include <string.h>

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