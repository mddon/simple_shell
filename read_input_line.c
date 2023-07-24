#include "main.h"

/**
 * read_line - this function reads a line of input from stdin.
 *
 * Return: Pointer to a dynamically allocated string containing the
 * line content.
 */

char *read_line(void)
{
	char *line_buffer = NULL;
	size_t buffer_size = 0;

	if (getline(&line_buffer, &buffer_size, stdin) == -1) /* If getline fails */
	{
		if (feof(stdin)) /* Test for the eof */
		{
			free(line_buffer); /* Avoid memory leaks when Ctrl + D is pressed */
			exit(EXIT_SUCCESS); /* Terminate the program after receiving EOF */
		}

		else
		{
			free(line_buffer); /* Avoid memory leaks when getline fails */
			perror("Error while reading the line from stdin\n");
			exit(EXIT_FAILURE); /* Terminate the program with an error code */
		}
	}

	return (line_buffer); /*Return the dynamically allocated line_buffer*/
}
