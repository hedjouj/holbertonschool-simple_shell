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
	char *command_path;

	if (args[0] == NULL || args == NULL)
	{
		return(1);
	}

	pid = fork();

	if (pid == 0)
	{
		/* v√rifie si la commande contient un chemin*/
		if (strchr(args[0], '/') != NULL)
		{
			execve(args[0], args, environ);
		}
		else
		{
			command_path = get_path(args[0]);
			if (command_path)
			{
				execve(command_path, args, environ);
				free(command_path);
			}
		}
		
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			exit(127);
		}
	}

	else if (pid < 0)
	{
		perror("fork");
		return (1);
	}
	else

	{	/* Processus du parent*/ 
		waitpid(pid, &status, 0);

		if (WIFEXITED(status)) /* renvoie vrai si le fils s'est termin√© normalement*/
			return (WEXITSTATUS(status)); /* renvoie le code de sortie du fils*/

	}


	return (1);
}
