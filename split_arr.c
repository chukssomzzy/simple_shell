# include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * split_t_arr - split string into array
 * @s: string to split
 * @dl: delimiter
 * Return: pointer to the string
 */

char **split_t_arr(char *s, const char *dl)
{
	char **argv;
	size_t n = 100;
	size_t i = 1;
	char *str;

	argv = malloc(sizeof(*argv) * n);
	for (str = s; ; str = NULL, i++)
	{
		if (i == n)
		{
			i = 10;
			n += i;
			argv = realloc(argv, sizeof(*argv) * n);
		}
		*argv = strtok(str, dl);
	}
	return (argv);
}
