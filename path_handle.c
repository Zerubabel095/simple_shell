#include "shell.h"

/**
 *
 *
 *
 *
 */
char *path_finder(void)
{
	char **env;
	char *path;

	env = environ;
	path = NULL;
	do {
		if (_strncmp(*env, "PATH=", 5) == 0) 
		{
			path = *env;
			path += 5;
			return path;
		}
		env++;
	} while (*env);
	return (NULL);
}

