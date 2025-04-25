#include "shell.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * build_full_path - Builds a full path string from dir and command
 * @dir: Directory string
 * @command: Command name string
 *
 * Return: Newly allocated full path string
 */
char *build_full_path(char *dir, char *command)
{
	char *full_path = malloc(strlen(dir) + strlen(command) + 2);

	if (!full_path)
		return (NULL);

	sprintf(full_path, "%s/%s", dir, command);
	return (full_path);
}

/**
 * run_exec - Forks and runs execve
 * @path: Full path to command
 * @args: Argument vector
 *
 * Return: Exit status code
 */
int run_exec(char *path, char **args)
{
	pid_t pid = fork();
	int status;

	if (pid == 0)
	{
		execve(path, args, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
		waitpid(pid, &status, 0);
	else
		perror("fork");

	return (WIFEXITED(status) ? WEXITSTATUS(status) : 1);
}

/**
 * find_path - Find the full path of a command using PATH
 * @command: command to locate
 *
 * Return: Full path if found, NULL otherwise
 */
char *find_path(char *command)
{
	char *path_env, *path_copy, *dir, *full_path;

	if (!command)
		return (NULL);

	if (strchr(command, '/'))
		return (access(command, X_OK) == 0 ? strdup(command) : NULL);

	path_env = my_getenv("PATH");
	if (!path_env || !*path_env)
		return (NULL);

	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = build_full_path(dir, command);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

/**
 * execute_command - Forks and executes a command
 * @args: Null-terminated array of command and arguments
 *
 * Return: 0 on success, 1 on error
 */
int execute_command(char **args)
{
	char *cmd_path;
	int status;

	if (!args || !args[0])
		return (1);

	if (strchr(args[0], '/'))
		return (access(args[0], X_OK) == 0 ? run_exec(args[0], args) : 1);

	cmd_path = find_path(args[0]);
	if (!cmd_path)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		return (127);
	}


	status = run_exec(cmd_path, args);
	free(cmd_path);
	return (status);
}

/**
 * handle_cd - Handles the cd command
 * @args: Array of arguments from the user input
 *
 * Description:
 * - If no argument, change directory to $HOME.
 * - If argument is "-", change to previous directory (OLDPWD).
 * - Otherwise, change to the directory specified.
 * - Updates the environment variable PWD after directory change.
 */
void handle_cd(char **args)
{
	static char *oldpwd = NULL; /* save the last directory*/
	char *dir = args[1];
	char cwd[1024];

	if (dir == NULL) { /* cd without any argument*/
		dir = getenv("HOME");
		if (dir == NULL) {
			fprintf(stderr, "cd: HOME not set\n");
			return;
		}
	}
	else if (strcmp(dir, "-") == 0) { /* if cd with -*/
		if (oldpwd == NULL) {
			fprintf(stderr, "cd: OLDPWD not set\n");
			return;
		}
		printf("%s\n", oldpwd); /* Display the previous pwd*/
		dir = oldpwd;
	}

	if (getcwd(cwd, sizeof(cwd)) == NULL) {
		perror("getcwd");
		return;
	}

	if (chdir(dir) != 0) { /* if the change failed*/
		perror("cd");
	} else {
		/* if change success*/
		free(oldpwd);
		oldpwd = strdup(cwd); /* Keep the previous pwd*/

		if (getcwd(cwd, sizeof(cwd)) != NULL) {
			setenv("PWD", cwd, 1); /* Update the pwd*/
		}
	}
}
