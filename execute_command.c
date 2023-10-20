#include "shell.h"

/**
 * execute_command - executes commands
 *@cp: it is command
 *@cmd: array of pointers
 * Return: 0
 */
void execute_command(char* cp, char** cmd)
{
	int result;
	pid_t pid;
	char **env;

	env = environ;
	pid = fork();
	if (pid < 0)
		perror(cp);
	if (pid == 0)
	{
		execve(cp, cmd, env);
		perror(cp);
		free(cp);
		buffer_free(cmd);
		exit(98);
	}
	else
		wait(&result);

}
