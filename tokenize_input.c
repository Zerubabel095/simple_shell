#include "shell.h"

/**
* tokenize_input - produce tokens
* @input : input to be tokenized
*
* Return: strings of array
*/
char **tokenize_input(char *input)
{
	char *buf = NULL, *buffer_ptr= NULL, *Token = NULL, *delim = " :\t\r\n";
	char **tokenize = NULL;
	int token_size = 1;
	size_t count = 0, flag = 0;

	buf = _strdup(input);
	if (!buf)
		return (NULL);
	buffer_ptr = buf;

	while (*buffer_ptr)
	{
		if (_strchr(delim, *buffer_ptr) != NULL && flag == 0)
		{
			token_size++;
			flag = 1;
		}
		else if (_strchr(delim, *buffer_ptr) == NULL && flag == 1)
			flag = 0;
		buffer_ptr++;
	}
	tokenize = malloc(sizeof(char *) * (token_size + 1));
	Token = strtok(buf, delim);
	while (Token)
	{
		tokenize[count] = _strdup(Token);
		if (tokenize[count] == NULL)
		{
			free(tokenize);
			return (NULL);
		}
		Token = strtok(NULL, delim);
		count++;
	}
	tokenize[count] = '\0';
	free(buf);
	return (tokenize);
}
