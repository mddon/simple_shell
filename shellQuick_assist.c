#include "main.h"

/**
 * assist - Print help information for the simple shell program.
 *
 * @args: Command-line arguments (not used in this function).
 *
 * Return: Always returns 1 to indicate successful execution.
 */

int assist(char **args)
{
	char *builtin_func_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	unsigned long int k_loop = 0;
	(void)(**args);

	printf("\n---help simple_shell---\n");
	printf("Type a command and its arguments, then hit enter\n");
	printf("Built-in commands:\n");

	while (k_loop < sizeof(builtin_func_list) / sizeof(char *))
	{
		printf("  -> %s\n", builtin_func_list[k_loop]);
		k_loop++;
	}

	printf("Use the man command for information on other programs.\n\n");

	return (-1);
}
