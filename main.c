#include "main.h"

/**
 * main - function that checks if our shell is called
 *
 * Return: return 0 if program is successfull
 */

int main(void)
{

	if (isatty(STDIN_FILENO) == 1)
	{
		shell_interactive();
	}

	else
	{
		shell_no_interactive();
	}

	return (0);
}
