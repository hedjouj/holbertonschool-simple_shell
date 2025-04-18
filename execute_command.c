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

	if (args[0] == NULL || args == NULL)
	{
		return(1);
	}

	pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			exit(127);
		}
	}

	else 
	{	/* Processus du parent*/ 
		waitpid(pid, &status, 0);

		if (WIFEXITED(status)) /* renvoie vrai si le fils s'est terminé normalement*/
			return (WEXITSTATUS(status)); /* renvoie le code de sortie du fils*/

	}


	return (1);
}
