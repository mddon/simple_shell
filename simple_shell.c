#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * display_prompt - Displays the shell prompt.
 */
void display_prompt(void)
{
	printf("$ ");
	fflush(stdout);
}

/**
 * execute_command - Executes the given command with arguments.
 * @command: The command to be executed.
 * @args: An array of arguments for the command.
 */
void execute_command(char *command, char *args[])
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process */
		execvp(command, args);
		perror("Command execution failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		(void)wait(NULL);
	}
}

/**
 * parse_command - Parses the command into an array of arguments.
 * @command: The command to be parsed.
 * Return: An array of arguments.
 */
char **parse_command(char *command)
{
	static char *args[MAX_ARGS];
	int arg_count = 0;

	char *token = strtok(command, " ");

	while (token != NULL)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;

	return (args);
}

/**
 * custom_getline - Custom implementation of getline to read input efficiently.
 * @lineptr: A pointer to the buffer containing the line read.
 * @n: A pointer to the size of the buffer.
 * @stream: The input stream to read from.
 * Return: The number of characters read (excluding the newline character).
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
    size_t buf_size = 0;
    size_t i;
    int c;

    if (lineptr == NULL || n == NULL || stream == NULL)
    {
        errno = EINVAL;
        return -1;
    }

    /* Allocate initial buffer size */
    if (*lineptr == NULL || *n == 0)
    {
        *n = MAX_BUFFER_SIZE;
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL)
        {
            perror("malloc");
            return -1;
        }
    }

    for (i = 0; ; i++)
    {
        c = fgetc(stream);

        /* End of File */
        if (c == EOF)
        {
            (*lineptr)[i] = '\0';
            break;
        }

        /* Expand buffer if necessary */
        if (i >= *n - 1)
        {
            buf_size = *n + MAX_BUFFER_SIZE;
            *lineptr = (char *)realloc(*lineptr, buf_size);
            if (*lineptr == NULL)
            {
                perror("realloc");
                return -1;
            }
            *n = buf_size;
        }

        (*lineptr)[i] = c;

        /* End of Line */
        if (c == '\n')
        {
            (*lineptr)[i + 1] = '\0';
            break;
        }
    }

    return i;
}
