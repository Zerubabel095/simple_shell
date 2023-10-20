#include "shell.h"

/**
* builtins - helps to execute builtins
* @command_args: commands tokenized by tokenize_input
* @input: standard input
*
* Return: 1 success, 0 fail
*/
int builtins(char **command_args, char *input)
{
	struct builtin builtin;

	builtin.env = "env";
	builtin.exit = "exit";
	if (_strcmp(*command_args, builtin.env) == 0)
	{
		environment();
		return (1);
	}
	else if (_strcmp(*command_args, builtin.exit) == 0)
	{
		exit_shell(command_args, input);
		return (1);
	}
	return (0);
}
