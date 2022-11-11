# include "main.h"
#include <stdio.h>
#include <string.h>
static pathnode_t *create_path_node(char *);
static int  check_link_cmd(char *p);
static char *_strcat(char *d, char *s);
static void free_list(pathnode_t *p);

/**
 * getpath -  absolute path to a cmd
 * @p: pointer to path
 * Return: absolute path
 */

char *getpath(char *p)
{
	pathnode_t *path;
	char *pathname;

	if (check_link_cmd(p))
		return (p);
	path = create_path_node("PATH");
	while (path->next)
	{
		pathname = _strcat(path->p, p);
		if (!check_dir(pathname, NULL))
		{
			free(pathname);
			free(p);
			return (pathname);
		}
		free(pathname);
	}
	free(p);
	free_list(path);
	return (NULL);
}


/**
 * create_path_node - create a struct containing pathname
 * @p: envname
 * Return: head
 */

pathnode_t *create_path_node(char *p)
{
	pathnode_t *head, *tmp;
	char *pathname = _getenv(p);
	char *str;
	int i = 0;

	head = malloc(sizeof(pathnode_t));
	if (!head)
	{
		perror("malloc");
		exit(1);
	}
	for (str = pathname; ; str = NULL)
	{
		if (!i)
		{
			strtok(str, "=:");
			head->p = strtok(str, "=:");
			head->next = malloc(sizeof(pathnode_t));
			if (!(head->next))
			{
				perror("malloc");
				exit(1);
			}
			tmp = head;
			i++;
			continue;
		}
		if (!head && i)
		{
			tmp->p = strtok(str, "=:");
			if (!(tmp->p))
				break;
			tmp->next = malloc(sizeof(pathnode_t));
			if (tmp->next)
			{
				perror("malloc");
				exit(1);
			}
		}

	}
	return (head);
}

/**
 * check_link_cmd - check if link a relative check_link_cmd
 * @p: path;
 *
 * Return: 1 or 0
 */

int  check_link_cmd(char *p)
{
	char *s = p;

	while ((*s))
		if (*s++ == '/')
			return (1);
	return (0);
}

/**
 * _strcat - councanate two strings
 * @d: first
 * @s: second
 * Return: return pointer or NULL
 */

char *_strcat(char *d, char *s)
{
	size_t dlen = _strlen(d), slen = _strlen(s);
	char *t;
	int i = 0, j = 0;

	if (!d)
		return (NULL);
	if (!s)
		return (d);
	t = malloc(sizeof(char) * (dlen + slen + 1));
	if (!t)
	{
		perror("malloc");
		exit(1);
	}

	while (*(d + i))
	{
		*(t + i) = *(d + i);
		i++;
	}
	while (*(s + j))
		*(t + i++) = *(s + j++);
	return (t);
}

/**
 * free_list - frees path free_list
 * @p: points to struct
 */

void free_list(pathnode_t *p)
{
	pathnode_t *tmp;

	while ((tmp = p->next))
	{
		free(p);
		p = tmp;
	}
	free(p);
}
