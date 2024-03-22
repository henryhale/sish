#ifndef SHELL_H
#define SHELL_H

/* shell name */
#define SHELL_NAME "sish"

/* maximum input size - 1kb */
#define MAX_INPUT 1024

/* structure of shell's state */
struct shell_state {
  char *name;
  char *input;
  char *args[MAX_INPUT];
};

void init_shell(int argc, char *argv[], struct shell_state *const state);

void clean_up(struct shell_state *const state);

char *prompt(char *const name);

void tokenize(char *const input, char *args[], const char delimiters[]);

void exec_command(char *args[], char *const name);

#endif
