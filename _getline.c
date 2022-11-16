# include "main.h"
# include <unistd.h>
static int _getchar(void);
static void *_realloc(void *ptr, size_t size);

/**
 * _getline - get line from stdin
 * @s: buffer to store string
 * @n: size of buffer
 * Return: pointer number of character read
 */

ssize_t _getline(char *s, int *n)
{
	int i = 0;
	int c;

	if (!n)
		*n = 128;
	if (!s)
		s = malloc(sizeof(char) * *n);
	while ((c = _getchar()) != -1)
	{
		if (c != '\0')
		{
			if (!(i < *n))
			{
				*n += 128;
				s = _realloc(s, *n);
			}
			*(s + i) = c;
			i++;
			if (c == '\n')
				break;
		} else
			return (-1);
	}
	return (i + 1);
}


/**
 * _getchar - read a char from stdin
 * Return: number of char read
 */

int _getchar(void)
{
	int c;

	read(STDIN_FILENO, &c, 1);
	return (c);
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
