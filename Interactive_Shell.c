#include "main.h"

/**
 * shell_interactive - UNIX command line interpreter
 *
 * Return: void
 */
void shell_interactive(void)
{
	int exit_status = -1;
	char *input_line;
	char **arguments;

	while (exit_status == -1)
	{
		printf("-$ "); /* print prompt symbol */
		input_line = read_line(); /* read line from stdin */
		arguments = split_line(input_line); /* tokenize line */
		exit_status = execute_args(arguments);

		/*frees unused memory to avoid leaks*/
		free(input_line);
		free(arguments);
	}

	if (exit_status >= 0)
	{
		exit(exit_status);
	}
}
