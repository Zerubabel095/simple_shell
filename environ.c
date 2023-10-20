#include "shell.h"
#include <unistd.h>

/**
 * environment - prints the environment
 *
 * Return: 0
 */
void environment(void)
{
	int i = 0;
	char **env = environ;

	while (env[i])
	{
		write(STDOUT_FILENO, (const void *)env[i], _strlen(env[i]));
            	write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

