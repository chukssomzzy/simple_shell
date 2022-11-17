# include "main.h"
int _strcmp(char *s, char *t);
/**
 * getbuiltin - return builtin
 * @s: string to cmp
 * Return: function
 */

int (*getbuiltin(char *s))(void)
{
	shellbuiltin_t builtin[] = {
		{"exit", exitfun},
		{"env", envfun},
		{NULL, NULL}
	};
	int i = 0;

	while ((builtin + i)->s)
	{
		if (_strcmp(s, (builtin + i)->s) == 0)
			return (*builtin->cmdfunc);
		i++;
	}
	return (NULL);
}

/**
 * _strcmp - compares two string
 * @s: pointer to string
 * @t: pointer to second string
 * Return: 0 if equal
 */

int _strcmp(char *s, char *t)
{
	size_t i = 0;

	while (*(s + i) == *(t + i))
	{
		if (*(s + i) == '\0')
			return (0);
		i++;
	}

	return (*(s + i) - *(t + i));
}
