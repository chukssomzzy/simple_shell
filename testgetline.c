# include "main.h"
#include <stdio.h>

/**
 * main - test _getline
 * Return: 0
 */

int main(void)
{
	char *buf = NULL;
	int n = 0;
	int lnr;

	while ((lnr = _getline(&buf, &n)) != EOF)
	{
		printf("%s", buf);
		fflush(stdout);
		free(buf);
		buf = NULL;
	}
	free(buf);
	return (0);
}
