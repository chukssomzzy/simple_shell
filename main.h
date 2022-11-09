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

extern char **environ;
int _putchar(char c);
char **split_t_arr(char *s, const char *dl, size_t *n);
int shell_cntrl(char **argv);
void print_line(char *s);

# endif
