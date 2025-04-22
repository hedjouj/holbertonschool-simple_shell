#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char *find_path(char *command)
{
	char *path_env, *path_copy, *dir, *full_path;
	struct stat st;

	if (command == NULL)
		return (NULL);

	if (stat(command, &st) == 0)
		return (strdup(command));

	path_env = my_getenv("PATH");
	if (!path_env)
		return (NULL);

	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", dir, command);
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	free(path_env);
	return (NULL);
}	



/**
 * execute_command - runs the command*/

int execute_command(char **args)
{
	pid_t pid;
	int status;
	char *cmd_path = NULL;

	if (args[0] == NULL)
	{
		return (1);
	}


	/* if it's an absolute or relative path */
	if (access(args[0], X_OK) == 0)
		cmd_path = strdup(args[0]);
	else
		cmd_path = find_path(args[0]);

	if (!cmd_path)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		free(args);
		exit(127);
	}

	pid = fork();
	if (pid == 0)
	{
		execv(cmd_path, args);
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		free(cmd_path);
		exit(127);
	}
	else if (pid < 0)
	{
		perror("fork");
		free(cmd_path);
		return (1);
	}
	else
	{
		waitpid(pid, &status, 0);
		free(cmd_path);
		if (WIFEXITED(status))
			return WEXITSTATUS(status);
					else
					return(1);
	}
}
