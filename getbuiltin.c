# include "main.h"

/**
 * getbuiltin - return builtin
 * @s: string to cmp
 * Return: function
 */

int (*getbuiltin(char *s))(void)
{
	shellbuiltin_t builtin[] = {
		{"exit", exitfun},
		{NULL, NULL}
	};
	int i = 0;

	while ((builtin + i)->s)
	{
		if (strcmp(s, (builtin + i)->s) == 0)
			return (*builtin->cmdfunc);
		i++;
	}
	return (NULL);
}
