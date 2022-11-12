# ifndef _MAIN_H_
# define _MAIN_H_
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <string.h>

/**
 * struct pathnode - linked list containing path
 * @p: pathname
 * @next: next node
 */

typedef struct pathnode
{
	char *p;
	struct pathnode *next;
} pathnode_t;

extern char **environ;
int _putchar(char c);
char **split_t_arr(char *s, const char *dl, size_t *n);
int shell_cntrl(char **argv);
void print_line(char *s);
char *_getenv(char *n);
char *getpath(char *p);
int check_dir(char *p, char *c);
size_t _strlen(char *s);
char *getpath(char *p);
char *_strdup(char *s);
# endif
