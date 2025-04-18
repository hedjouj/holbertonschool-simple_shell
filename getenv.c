#include <string.h>

extern char **env;

char *getenv(const char *name)
{
	int i = 0;
	size_t len = strlen(name);

	while (env[i])
	{
		/* Compare the vars name with the start of the line*/
		if (strncmp(env[i], name, len) == 0 && env[i][len] == '=')
		{
			/* Return a pointer to the value , after the '='*/
			return &env[i][len + 1];
		}
		i++;
	}

	return NULL; /* No founded env variable*/
}
