#include "main.h"

/**
 * new_process - this function creates a new process and execute a
 * command with its flags.
 *
 * @args: Array of strings containing the command and its flags.
 *
 * Return: 1 if success, 0 otherwise.
 */

int new_process(char **args)
{
	pid_t pid;
	int child_exit_status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Error in new_process: child process");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Error in new_process: forking");
	}
	else
	{
		do {
			if (waitpid(pid, &child_exit_status, WUNTRACED) == -1)
			{
				perror("Error in new_process: waitpid");
				break;
			}
		} while (!WIFEXITED(child_exit_status) && !WIFSIGNALED(child_exit_status));
	}

	return (-1);
}
