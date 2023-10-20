#include "shell.h"

/**
* get_path_command - tests the path
* @path: path tokenized by tokenize_input
* @command_args: standard input commmand
*
* Return: additional path success, NULL fail
*/
char *get_path_command(char **path, char *command_args)
{
	char *result;
	int x;

	while (path[x])
	{
		result = add_path(path[x], command_args);
		if (access(result, F_OK | X_OK) == 0)
			return (result);
		free(result);
		x++;
	}
	return (NULL);
}
