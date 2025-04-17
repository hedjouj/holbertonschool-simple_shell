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

	if (args[0] == NULL)
	{
		return(1);
	}

	pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			exit(0);
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
