# include "main.h"
# include <stdio.h>
#include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# define DELIM " \n"
static void free_buf(char **buf, size_t n);
static size_t word_count(char *b);

/**
 * main - starting point for execution
 * @argc: Size of argv
 * @argv: Contains cmd args
 * Return: 0 (successe))
 */


int main(int argc, char **argv)
{
	char *line = NULL, *p = argv[argc - 1];
	size_t n;
	ssize_t lnr;
	size_t arr_size = 1;
	char **lines;
	char *tmp;

	do {
		print_line(NULL);
		lnr = getline(&line, &n, stdin);
		if (lnr == -1)
		{
			perror("getline");
			exit(1);
		}
		arr_size = word_count(line);
		lines = split_t_arr(line, DELIM, &arr_size);
		tmp = lines[0];
		lines[0] = getpath(lines[0]);
		if (!lines)
		{
			perror("split_t_arr");
			exit(1);
		}
		if (check_dir(lines[0], p))
		{
			free(line);
			free(tmp);
			free_buf(lines, arr_size);
			continue;
		}
		if ((shell_cntrl(lines)))
		{
			perror("shell_cntrl");
			exit(1);
		}
		free(tmp);
		free_buf(lines, arr_size);
		free(line);
	} while (lnr != EOF);
	exit(EXIT_SUCCESS);
}

/**
 * free_buf - free free_buf
 * @buf: buf to free
 * @n: Number of pointer in free_buf
 */

void free_buf(char **buf, size_t n)
{
	size_t i = 0;

	while (i < n)
		free(*(buf + i++));
	free(buf);
}

/**
 * check_dir - find referred file
 * @p: pathname to folder
 * @c: pathname to calling process
 * Return: 0(True)
 */

int check_dir(char *p, char *c)
{
	struct stat st;

	if (stat(p, &st) == 0)
		return (0);
	if (c)
		dprintf(STDERR_FILENO, "%s: 1: %s: not found\n", c, p);
	return (1);
}

/**
 * word_count - find number of word in buffer
 * @b: buffer
 * Return: number of word
 */

size_t word_count(char *b)
{
	size_t n = 0;
	char *s = b;

	while (*s)
	{
		if (*s == ' ' || *s == '\t' || *s == '\n')
			n++;
		s++;
	}
	return (n);
}
