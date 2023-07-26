#include "main.h"
/**
 * read_stream - Read a line from the input stream (stdin).
 * Return: A pointer to the read line as a dynamically allocated string.
 */
char *read_stream(void)
{
	int bufferSize = 1024; /*Initial buffer size for reading the line*/
	char *line = malloc(sizeof(char) * bufferSize);	/*Allocate memory to line*/
	int character; /*Variable to store the read character*/
	int line_idx = 0; /*Index to track the current position in the line*/

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
				fprintf(stderr, "Reallocation error in read_stream\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
