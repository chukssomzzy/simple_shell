# include "main.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
static char *find_env(char **e, char *p);
/**
 * _getenv - return a pointer to environi
 * @n: name to find
 * Return: pointer or NULL
 */

char *_getenv(char *n)
{
	return (_strdup(find_env(environ, n)));
}

/**
 * find_env - find env and return a pointer to the env
 * @e: pointer to env
 * @p: pointer to env to find
 * Return: pointer
 */

char *find_env(char **e, char *p)
{
	size_t i = 0;

	if (!e)
		return (NULL);
	if (!p)
		return (NULL);
	while (*(e + i))
	{
		size_t j = 0;

		while (*(*(e + i) + j) == *(p + j))
		{
			if (!(*(p + j + 1)) && *(*(e + i) + j + 1) == '=')
				return (*(e + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
/**
 * _strlen - str len
 * @s: pointer to string len
 * Return: Length of string
 */

size_t _strlen(char *s)
{
	char *d = s;

	if (!s)
		return (0);
	while (*d)
		d++;
	return (d - s);
}

/**
 * _strdup - str duplicate
 * @s: pointer to string to duplicate
 * Return: pointer
 */

char *_strdup(char *s)
{
	size_t len, i = 0;
	char *d;

	if (!s)
		return (NULL);
	len = _strlen(s);
	d = malloc(sizeof(char) * (len + 1));
	if (!d)
	{
		perror("Malloc");
		exit(EXIT_FAILURE);
	}
	while ((*(d + i) = *(s + i)))
		i++;
	return (d);
}


