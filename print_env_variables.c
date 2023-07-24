#include "main.h"

/**
 * env - function that prints environment variables
 * @args: arguments (not used in this function)
 *
 * Return: 1 on success, 0 otherwise
 */
int env(char **args)
{
	int i_loop = 0;
	(void)(**args);

	/*do-while loop to handle printing environment variables*/
	do {
		write(STDOUT_FILENO, environ[i_loop], strlen(environ[i_loop]));
		write(STDOUT_FILENO, "\n", 1);
		i_loop++;
	} while (environ[i_loop]);

	return (-1);
}
