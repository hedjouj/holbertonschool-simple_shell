#include <string.h>
#include "shell.h"
/**
 * my_getenv - Retrieves the value of an environment variable
 * @name: Name of the variable to find
 *
 * Return: Pointer to the value of the variable, or NULL if not found
 */

char *my_getenv(const char *name)
{
	int i = 0;
	size_t len = strlen(name);

	while (environ[i])
	{
		/* Compare the vars name with the start of the line*/
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			/* Return a pointer to the value , after the '='*/
			return (&environ[i][len + 1]);
		}
		i++;
	}

	return (NULL); /* No founded env variable*/
}
