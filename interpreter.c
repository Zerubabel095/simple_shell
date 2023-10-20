#include "shell.h"
/**
* main - read, execute and print 
* 
* Return: 0
*/

int main(int argc, char **argv, char *envn[])
{
	char *input = NULL; 
	char *path_command = NULL; 
	char *path = NULL;
	size_t buffer_size = 0;
	ssize_t line_size = 0;
	char **command_args = NULL;
       	char **path_dirs = NULL;

	(void)envn, (void)argc;
	if (argc < 1)
		return (-1);
	signal(SIGINT, _signal);
	while (1)
	{
		buffer_free(command_args);
		buffer_free(path_dirs);
		free(path_command);

		print_prompt();
		line_size = getline(&input, &buffer_size, stdin);
		if (line_size < 0)
			break;
		info.line_number++;
		if (input[line_size - 1] == '\n')
			input[line_size - 1] = '\0';
		command_args = tokenize_input(input);
		if (command_args == NULL || *command_args == NULL || **command_args == '\0')
			continue;
		if (builtin_check(command_args, input))
			continue;
		path = path_finder();
		path_dirs = tokenize_input(path);
		path_command = get_path_command(path_dirs, command_args[0]);
		if (!path_command)
			perror(argv[0]);
		else
			execute_command(path_command, command_args);
	}
	if (line_size < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(input);
	return (0);
}
