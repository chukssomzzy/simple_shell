# include "main.h"
#include <sys/types.h>
# include <unistd.h>
static void *_realloc(void *ptr, size_t size);

/**
 * _getline - get line from stdin
 * @s: buffer to store string
 * @n: size of buffer
 * Return: pointer number of character read
 */

ssize_t _getline(char **s, int *n)
{
	int i = 0;
	ssize_t numrd;
	char *tmpptr;

	if (!n)
		*n = 128;
	if (!*s)
		*s = malloc(sizeof(char) * *n);
	if (!*s)
	{
		perror("malloc");
		exit(1);
	}
	tmpptr = *s;
	while  ((numrd = read(STDOUT_FILENO, *s, *n)) >= 0)
	{
		int tmp = i;

		while (i < (tmp + numrd))
			if (*(*s + i++) == '\n')
			{
				*(*s + i) = '\0';
				*s = tmpptr;
				return (i);
			} else if ((int) *(*s + i - 1) == EOF)
				return (EOF);
		if (i >= (*n - 1))
		{
			*n += 128;
			*s = _realloc(*s, *n);
			if (!*s)
			{
				perror("_realloc");
				exit(1);
			}
		}
		*s = (*s + i);
	}
	return (-1);
}


/**
 * _realloc - copies a buffer and increses it size
 * @ptr: pointer to allocated buffer
 * @size: new size
 * Return: ptr
 */

void *_realloc(void *ptr, size_t size)
{
	char *newptr, *oldptr = (char *) ptr;
	size_t i = 0;

	if (!ptr && !size)
		return (NULL);
	if (!ptr && size)
	{
		free(ptr);
		return (malloc(size));
	}
	newptr = malloc(size);
	if (!newptr)
	{
		perror("malloc");
		exit(1);
	}
	while (i < size)
	{
		*(newptr + i) = *(oldptr + i);
		i++;
	}
	free(ptr);
	return (newptr);
}
