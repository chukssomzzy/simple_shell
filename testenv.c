# include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - test
 * @argc: size
 * @argv: array
 * Return: 1 0
 */

int main(int argc, char **argv)
{
	char *env;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s %s\n", argv[0], argv[1]);
		exit(EXIT_FAILURE);
	}
	env = _getenv(argv[1]);
	dprintf(STDOUT_FILENO, "%s: %s\n", argv[1], env);
	exit(EXIT_SUCCESS);
}
