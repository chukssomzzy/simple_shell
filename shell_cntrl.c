# include "main.h"
#include <unistd.h>


/**
 * shell_cntrl - fork children
 * @argv: array to pass to argv
 * Return: 1 (success)
 */

int shell_cntrl(char **argv)
{
	pid_t child_pid;
	int status;
	ssize_t w;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror("fork");
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(*argv, argv, environ) < 0)
		{
			perror("execve");
			return (1);
		}
	} else
		do {
			w = waitpid(child_pid, &status, WUNTRACED);
			if (w == -1)
			{
				perror("waitpid");
				return (1);
			}
		} while (!WIFSIGNALED(status) && !WIFEXITED(status));
	return (0);
}

