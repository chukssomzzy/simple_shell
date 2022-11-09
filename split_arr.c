# include "main.h"
#include <stdio.h>

/**
 * split_t_arr - split string into array
 * @s: string to split
 * @dl: delimiter
 * @n: holds size
 * Return: pointer to the string
 */

char **split_t_arr(char *s, const char *dl, size_t *n)
{
	char **argv;
	size_t i = 1;
	char *str;

	argv = malloc(sizeof(*argv) * *n);
	if (!argv)
	{
		perror("malloc");
		return (NULL);
	}
	for (str = s; ; str = NULL, i++)
	{
		if (i == *n)
		{
			i = 10;
			n += i;
			argv = realloc(argv, sizeof(*argv) * *n);
			if (!argv)
			{
				perror("realloc");
				return (0);
			}
		}
		*argv = strtok(str, dl);
	}
	return (argv);
}
