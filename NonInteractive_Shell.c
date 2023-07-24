#include "main.h"

/**
 * shell_no_interactive - interpreter for unix command lin.
 *
 * Return: return void.
 */

void shell_no_interactive(void)
{
	int exit_status -1;
	char *input_line;
	char **arguments;

	while (exit_status == -1)
	{
		input_line = read_stream();
		arguments = split_line(input_line); /* tokenize line */
		exit_status = execute_args(arguments);

		/*to free-up memory*/
		free(input_line);
		free(arguments);
	}

	if (exit_status >= 0)
	{
		exit(exit_status);
	}
}
