#include "shell.h"

/**
 *_signal- clears disruption in interactive mode
 *@s: number 
 *Return: no return
 */

void _signal(int s)
{
	(void)s;
	fputs("\n$ ", stderr);	
}
