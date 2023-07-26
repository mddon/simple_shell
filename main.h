#ifndef SHELL_H
#define SHELL_H

/*---LIBRARIES---*/
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


/*---PROTOTYPES---*/
/* main.c */
void shell_interactive(void);
void shell_no_interactive(void);

/*---Macros---*/
#define TOK_DELIM " \t\r\n\a\""
extern char **environ;

#define my_sizeof(type) (char *)(&type + 1) - (char *)(&type)
int main(void);

/* shell_no_interactive */
char *read_stream(void);

/* shell_interactive.c */
char **split_line(char *line);
char *read_line(void);
int execute_args(char **args);

/*---Builtin func---*/
int cd(char **args);
int env(char **args);
int own_exit(char **args);
int assist(char **args);

/* execute_args */
int new_process(char **args);

#endif
