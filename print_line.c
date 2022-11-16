# include "main.h"
#include <unistd.h>

/**
 * print_line - print current shell location
 * @s: pointer to string to add
 */

void print_line(char *s)
{
	if (!s)
		dprintf(STDOUT_FILENO, "($) ");
	else
		dprintf(STDOUT_FILENO, "~%s ($) ", s);
}
