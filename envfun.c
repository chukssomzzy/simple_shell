# include "main.h"
#include <unistd.h>

/**
 * envfun - print envs
 * Return: 0 1
 */

int envfun(void)
{
	size_t i = 0;
	char **env = environ;

	while (*(env + i))
		printf("%s\n", (*env + i++));
	return (0);
}
