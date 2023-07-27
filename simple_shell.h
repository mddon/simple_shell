#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>    /* Add this line for 'FILE' and 'environ' */
#include <string.h>   /* Add this line for 'strcmp' */

#define MAX_BUFFER_SIZE 1024
#define MAX_ARGS 10

/* Function prototypes */
char **parse_command(char *command);
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);
void execute_command(char *command, char *args[]);
void display_prompt();
void handle_env();
void handle_exit();
void run_shell();

#endif /* SIMPLE_SHELL_H */
