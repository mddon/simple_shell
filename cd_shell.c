#include "main.h"

/**
 * cd - this function changes the working directory of the current shell
 * executon environment.
 *
 * @args: target directory.
 *
 * Return: 1 one success, 0 otherwise.
 */

int cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "expected argument to \"cd\"\n");
	}

	if (chdir(args[1]) != 0)
	{
		perror("error in own_cd.c: changing dir\n");
	}

	return (-1);
}
