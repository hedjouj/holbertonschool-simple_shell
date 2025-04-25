#include "shell.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * display_prompt - Displays the shell prompt
 */
void display_prompt(void)
{
	printf("$ ");
	fflush(stdout); /* Force the immediat displaying of the prompt */
}

/**
 * split_line - Splits a line into tokens (words)
 * @line: The input line to split
 *
 * Return: Null-terminated array of tokens
 */
char **split_line(char *line)

{
	int bufsize = 64;
	int i = 0;
	char **tokens = malloc(sizeof(char *) * bufsize);
	char *token;

	if (!tokens)
	{
		perror("allocation");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\r\n");
	while (token != NULL)
	{
		tokens[i++] = token;
		token = strtok(NULL, " \t\r\n");
	}
	tokens[i] = NULL;

	return (tokens);
}

/**
 * handle_builtin - Handles builtin commands (exit, env, pwd)
 * @args: Array of arguments
 * @line: Line buffer to free if needed
 *
 * Return: -1 if not a builtin, 0 or exit otherwise
 */
int handle_builtin(char **args, char *line)
{
	if (args[0] == NULL)
	{
		return (0);
	}
	{
		if (strcmp(args[0], "exit") == 0)
		{

			free(args);
			free(line);
			exit(last_status);
		}
		if (strcmp(args[0], "env") == 0)
		{
			printenv();
			return (0);
		}
		else if (strcmp(args[0], "pwd") == 0)
		{
			char cwd[1024];

			if (getcwd(cwd, sizeof(cwd)) != NULL)

				printf("%s\n", cwd);
			else
				perror("getcwd");
			return (1); /*Error*/
		}
		if (strcmp(args[0], "cd") == 0)
		{
			handle_cd(args);
			return (0);
		}

		return (-1); /* Not a builtin */
	}
}

/**
 * printenv - Prints the current environment variables
 */
void printenv(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
}
