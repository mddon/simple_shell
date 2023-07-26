#include "main.h"

/**
 * own_exit - the function causes normal process termination.
 *
 * @args: Command-line arguments (unused in this function).
 *
 * Return: The exit status specified in the command-line arguments
 *         if provided, otherwise returns 0 for successful termination.
 */
int own_exit(char **args)
{
	if (args[1])
	{
		return (atoi(args[1]));
	}
	/* If no exit status is provided, return 0 for successful termination. */
	else
	{
		return (0);
	}
}
