#include "shell.h"


/**
 * main
 *
 * Return
 */

int main(void)
{
	char *line = NULL;
	char **args = NULL;
	size_t len = 0;
	ssize_t read;
	int status = 1;
	int interactive_mode = isatty(STDIN_FILENO) && isatty(STDERR_FILENO);
	while (status)
	{

		if (interactive_mode)

			display_prompt();	/* Display the prompt ("$ ") */
		read = getline(&line, &len, stdin); /* Read the standard user input */

		if (read == -1)		/* Gestion of EoF or Ctrl+D */
		{
			break;
		}

		args = split_line(line); /* Split the line on token */
		status = execute_command(args); /* Execute the commande enter by the user */
		free(args);
	}
	free(line);
}
