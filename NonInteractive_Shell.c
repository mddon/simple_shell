#include "main.h"

/**
 * shell_no_interactive - interpreter for unix command line.
 *
 * Return: return void.
 */

void shell_no_interactive(void)
{
	int status = -1;
	char *line;
	char **arguments;

	while (status == -1)
	{
		line = read_stream();
		arguments = split_line(line); /* tokenize line */
		status = execute_args(arguments);

		/*to free-up memory*/
		free(line);
		free(arguments);
	}

	if (status >= 0)
	{
		exit(status);
	}
}
