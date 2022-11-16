# include "main.h"

/**
 * main - test _getline
 * Return: 0
 */

int main(void)
{
	char *buf = NULL;
	int n = 0;
	int lnr;

	while ((lnr = _getline(buf, &n)))
	{
		printf("%s", buf);
		free(buf);
		buf = NULL;
	}
	free(buf);
	return (0);
}
