#include "shell.h"

/**
* buffer_free - which frees buffers
* @buf: Are buffers to be freed
*
* Return: nothing
*/
void buffer_free(char **buf)
{
	if (buf != NULL) 
	{
		free(buf);
		buf = NULL;
	}
}
