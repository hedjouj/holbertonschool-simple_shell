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
			perror("Error:");
			exit(127);
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
