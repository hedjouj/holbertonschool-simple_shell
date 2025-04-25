#include "shell.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern char **environ;

void display_prompt(void)
{
	printf("$ ");
	fflush(stdout); /* Force the immediat displaying of the prompt */
}

/*
 *
 *
 *
 *
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

int handle_builtin(char **args, char *line)
{
	if (args[0] == NULL)
	{
		return (0);
	}

	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(line);
		exit(last_status);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		printenv();
		return(0); /* Return 0 for success*/
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

	return (-1); /* Not a builtin */
}

void printenv(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
}
