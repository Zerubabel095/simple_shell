#include "shell.h"
/**
 *builtin_check - builtin functions checker
 *@cmd: input entered by user
 *@buf: getline function application
 *Return: 1 on execution 0 on failure
 */
int builtin_check(char **cmd, char *buf)
{
	if (builtins(cmd, buf))
		return (1);
	else if (**cmd == '/')
	{
		execute_command(cmd[0], cmd);
		return (1);
	}
	return (0);
}
