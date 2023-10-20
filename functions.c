#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
        return (write(1, &c, 1));
}
                                                       
/**
* str_print - string printer 
* @r : printed string 
*
* Return: number characters
*/
int str_print(char *r)
{
	int x = 0;

	while (r[x] != '\0')
	{
		_putchar(r[x]);
		x++;
	}

	return (x);
}

