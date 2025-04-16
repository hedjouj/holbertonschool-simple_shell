#include "shell.h"

/**
 * execute_command - execute the command of the user in the terminal
 *
 * return: the command choosed by the user 
 */

int execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("hsh");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else 
	{
		wait(&status);
	}

	return (1);
}
