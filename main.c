# include "main.h"
# include <stdio.h>
#include <unistd.h>
# define DELIM " \n"
 int check_dir(char *p, char *c)
static void free_buf(char **buf, size_t n);
/**
 * main - starting point for execution
 * @argc: Size of argv
 * @argv: Contains cmd args
 * Return: 0 (success())
 */


int main(int argc, char **argv)
{
	char *line, *p = argv[0];
	size_t n;
	ssize_t lnr;
	size_t arr_size = 100;
	char **lines;

	do {
		lnr = getline(&line, &n, stdin);
		print_line(NULL);
		if (lnr == -1)
		{
			perror("getline");
			free(line);
			exit(1);
		}
		lines = split_t_arr(line, DELIM, &arr_size);
		if (!lines)
		{
			perror("split_t_arr");
			free_buf(lines, arr_size);
			exit(1);
		}
		if (!(shell_cntrl(lines)))
		{
			perror("shell_cntrl");
			free_buf(lines, arr_size);
			exit(1);
		}
		print_line(NULL);
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
	dprintf(STDERR_FILENO, "%s: 1: %s: not found", c, p);
	return (1);
}

