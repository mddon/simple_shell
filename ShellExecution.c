#include "main.h"

/**
 * execute_args - this executes the command if it's a built_in function,
 * else it will create a new process.
 * @args: List of command and its flags.
 *
 * Return: returns 1 on success (if builtin executed), 0 otherwisg
 * (for new process).
 */

int execute_args(char **args)
{
	unsigned long int i_loop = 0;

	char *builtin_commands[] = {
		"cd",
		"env",
		"help",
		"exit"
		};

	int (*builtin_functions[])(char **) = {
		&cd,
		&env,
		&assist,
		&own_exit
		};

	if (args[0] == NULL)
	{
		return (-1);
	}

	/*Check if the command is a builtin using a do-while loop*/
	do {
		/*If there is a match, execute the corresponding builtin function*/
		if (strcmp(args[0], builtin_commands[i_loop]) == 0)
		{
			return ((*builtin_functions[i_loop])(args));
		}
		i_loop++;
	} while (i_loop < sizeof(builtin_commands) / sizeof(char *));

	/*If the command is not a builtin, create a new process*/
	return (new_process(args));
}
