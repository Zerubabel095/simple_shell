#include "shell.h"

/**
* exit_shell - helps to exit the shell
* @command_args: a command tokenized by tokenize_input
* @input: standard input
*
* Return: nothing
*/
void exit_shell(char **command_args, char *input)
{
	free(input);
	buffer_free(command_args);
	exit(0);
}
