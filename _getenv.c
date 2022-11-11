# include "main.h"
#include <stddef.h>
#include <unistd.h>
static char **_strdup(char **s);

/**
 * _getenv - return a pointer to environi
 * @n: name to find
 * Return: pointer or NULL
 */

char *_getenv(char *n)
{
	char **env = _strdup(environ);
	size_t i = 0;

	if (*n)
		return (NULL);
	while (*(env + i))
	{
		size_t j = 0;

		while (*(env + i)[j])
		{
			if (*(env + i)[j] != *(n + j))
				break;
			if (!(*(n + ++j)))
				return (*(env + i));
		}
		i++;
	}
	return (NULL);
}

/**
 * _strdup - duplicate string and return pointer
 * @s: pointer to string
 * Return: pointer to Null or string dupllicate
 */

char **_strdup(char **s)
{
	char **d;
	size_t i = 0, n, len = 20;

	if (!s)
		return (NULL);
	for (len = 0; *(s + len) != NULL; len++)
		;
	d = malloc(sizeof(*d) * 20);
	if (!d)
	{
		perror("malloc");
		exit(1);
	}
	while (*(s + i))
	{
		int j = 0;

		n = _strlen(*(s + i));
		*(d + i) = malloc(sizeof(char) * (n + 1));
		if (!(*(d + i)))
		{
			perror("malloc");
			exit(1);
		}
		while ((*(d + i)[j] = *(s + i)[j]))
			j++;
		i++;
	}
	*(d + ++i) = NULL;
	return (d);
}

/**
 * _strlen - str len
 * @s: pointer to string len
 * Return: Length of string
 */

size_t _strlen(char *s)
{
	char *d = s;

	while (*d)
		d++;
	return (s - d);
}


