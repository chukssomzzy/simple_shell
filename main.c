# include "main.h"
# include <stdio.h>
#include <unistd.h>
# define DELIM " \n"
static void free_buf(char **buf, size_t n);
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

	do {
		print_line(NULL);
		lnr = getline(&line, &n, stdin);
		if (lnr == -1)
		{
			perror("getline");
			free(line);
			exit(1);
		}
		lines = split_t_arr(line, DELIM, &arr_size);
		lines[0] = getpath(lines[0]);
		if (!lines)
		{
			free(line);
			perror("split_t_arr");
			free_buf(lines, arr_size);
			exit(1);
		}
		if (check_dir(lines[0], p))
		{
			free(line);
			free_buf(lines, arr_size);
			continue;
		}
		if ((shell_cntrl(lines)))
		{
			perror("shell_cntrl");
			free_buf(lines, arr_size);
			exit(1);
		}
	} while (lnr != EOF);
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
	if (access(p, F_OK | X_OK) != -1)
		return (0);
	if (c)
		dprintf(STDERR_FILENO, "%s: 1: %s: not found\n", c, p);
	return (1);
}

