#include "main.h"
/**
 * read_stream - Read a line from the input stream (stdin).
 *
 * Return: A pointer to the read line as a dynamically allocated string.
 *	The caller is responsible for freeing the allocated memory.
 *	Returns NULL in case of reaching EOF or a memory allocation error.
 */
char *read_stream(void)
{
	 /*Initial buffer size for reading the line*/
	int bufferSize = 1024;

	/*Allocate memory for the line*/
	char *line = malloc(sizeof(char) * bufferSize);

	/*Variable to store the read character*/
	int character;

	/*Index to track the current position in the line*/
	int line_idx = 0;

	if (line == NULL)
	{
		fprintf(stderr, "Error: Allocation error in read_stream\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = getchar();

		if (character == EOF)
		{
			free(line);
			return (NULL); /*Return NULL to indicate EOF reached*/
		}
		else if (character == '\n')
		{
			line[line_idx] = '\0';
			return (line); /*Return the dynamically allocated line*/
		}
		else
		{
			line[line_idx] = character;
		}
		line_idx++;
		if (line_idx >= bufferSize)
		{
			bufferSize += bufferSize;
			line = realloc(line, bufferSize);
			if (line == NULL)
			{
				fprintf(stderr, "Error: Reallocation error in read_stream\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
