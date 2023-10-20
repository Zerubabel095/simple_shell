#include "shell.h"

/**
* add_path  - adds path
* @path: the path in which the command executes 
* @command_args: command entered by the user
*
* Return: Sucess, buf command and  NULL, Failure
*/
char *add_path(char *path, char *command_args)
{
	char *buf;
	size_t L = 0, M = 0;

	if (command_args == 0)
		command_args = "";

	if (path == 0)
		path = "";

	buf = malloc(sizeof(char) * (_strlen(path) + _strlen(command_args) + 2));
	if (!buf)
		return (NULL);

	while (path[L])
	{
		buf[L] = path[L];
		L++;
	}

	if (path[L - 1] != '/')
	{
		buf[L] = '/';
		L++;
	}
	while (command_args[M])
	{
		buf[L + M]= command_args[M];
		M++;
	}
	buf[L + M] = '\0';
	return (buf);
}
