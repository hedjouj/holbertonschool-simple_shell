#include "shell.h"





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
