# include "main.h"


/**
 * _strtok - returns a pointer to the start of
 *			 found delim
 * @s: pointer to find
 * @d: search pointer
 * Return: NULL or pointer
 */

char *_strtok(char *s, char *d)
{
	static char *start;
	static char *cont;
	char *ds;

	if (!start && !s)
		return (NULL);
	if (!d)
		return (NULL);
	if (s)
		start = s;
	else
		start = cont;
	while (!*s)
	{
		ds = d;
		while (*d)
		{
			if (*s == *d)
			{
				*s = '\0';
				return (start);
			}
			d++;
		}
		d = ds;
		s++;
	}
	return (NULL);
}
