#include "main.h"

/**
 * split_line - Split a string into multiple substrings (tokens).
 * @line: The string to be split.
 *
 * Return: A pointer to a dynamically allocated array of strings (tokens).
 *         The caller is responsible for freeing the allocated memory.
 */
char **split_line(char *line)
{
	int bufferSize = 64;
	int k_loop = 0;
	char **tokens = malloc(bufferSize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "Error: Allocation error in split_line: tokens\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM); /*Get the first token*/

	while (token != NULL)
	{
		/* Handle comments */
		if (token[0] == '#')
		{
			break;
		}
		tokens[k_loop] = token;
		k_loop++;

		/*If the number of tokens exceeds the buffer size, reallocate memory*/
		if (k_loop >= bufferSize)
		{
			bufferSize += bufferSize; /*Double the buffer size*/
			tokens = realloc(tokens, bufferSize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Reallocation error in split_line: tokens\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM); /*Get the next token*/
	}
	tokens[k_loop] = NULL;
	return (tokens); /*Return the dynamically allocated array of tokens*/
}
