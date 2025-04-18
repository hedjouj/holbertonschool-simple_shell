#include "shell.h"
extern char **environ; /* Declare environ */

int main(void)
{
	char *line = NULL;
	char **args = NULL;
	size_t len = 0;
	ssize_t read;
	int status = 1;
	int interactive_mode = isatty(STDIN_FILENO) && isatty(STDERR_FILENO);

	while (1) /* Infinite loop, breaks only on EOF or exit */
	{
		if (interactive_mode)
			display_prompt(); /* Display the prompt ("$ ") */

		read = getline(&line, &len, stdin); /* Read user input */

		if (read == -1)
			break;

		args = split_line(line); /* Split the input line*/

		/* === Check for built-in commands === */

		if (handle_builtin(args))
		{
			free(args);
			continue;
		}

		status = execute_command(args);/* === External command execution === */
		free(args);
	}
	free(line);
	return (status);
}
