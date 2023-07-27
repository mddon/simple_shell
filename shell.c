#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

/**
 * handle_env - Handles the "env" command to print the current environment.
 */
void handle_env(void)
{
    char **env = environ;
    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }
}

/**
 * handle_exit - Handles the "exit" command to exit the shell.
 */
void handle_exit(void)
{
    exit(0);
}

/**
 * execute_command_or_not_found - Executes a command if found;
 * otherwise, prints an error message.
 */
void execute_command_or_not_found(char **args)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (child_pid == 0)
    {
        if (execve(args[0], args, environ) == -1)
        {
            perror("execve");
        }
        _exit(EXIT_FAILURE);
    }
    else
    {
        (void)wait(&status);
    }
}


/**
 * process_command - Processes a command and determines its action
 * (execute, env, or exit).
 */
void process_command(char *command)
{
    if (strcmp(command, "exit") == 0)
    {
        handle_exit();
    }
    else if (strcmp(command, "env") == 0)
    {
        handle_env();
    }
    else
    {
        char **args = parse_command(command);
        execute_command_or_not_found(args);
        free(args);
    }
}

/**
 * run_shell - Main loop of the shell, displays the prompt,
 * and processes user commands.
 */
void run_shell(void)
{
    char *command = NULL;
    size_t buffer_size = 0;

    while (1)
    {
        display_prompt();
        if (custom_getline(&command, &buffer_size, stdin) == -1)
        {
            putchar('\n');
            break;
        }
        if (strlen(command) == 0)
        {
            free(command);
            continue;
        }
        process_command(command);
        free(command);
    }
}
