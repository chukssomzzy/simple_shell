# include "main.h"
#include <stdio.h>
#include <string.h>
static pathnode_t *create_path_node(char *);
static int  check_link_cmd(char *p);
static char *_strcat(char *d, char *s);
static void free_list(pathnode_t *p);
static int find_e(char *p);
static pathnode_t *add_node_end(pathnode_t **head, char *str);
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
		if (!(check_dir(pathname, NULL)))
		{
			free_list(path);
			free(p);
			return (pathname);
		}
		free(pathname);
		path = path->next;
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
	pathnode_t *head = NULL;
	char *pathname, *str, *tmps;

	pathname = str = _getenv(p);
	for (str = pathname; ; str = NULL)
	{
		tmps = strtok(str, "=:");
		if (!tmps)
			break;
		if (find_e(tmps))
			head = add_node_end(&head, tmps);
	}
	free(pathname);
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
	t = malloc(sizeof(char) * (dlen + slen + 2));
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
	*(t + i++) = '/';
	while (*(s + j))
		*(t + i++) = *(s + j++);
	*(t + i) = '\0';
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

/**
 * add_node_end - add a node to end of lists
 * @head: parent lists
 * @str: str pointer
 *
 * Return: addr of element added
 */

pathnode_t *add_node_end(pathnode_t **head, char *str)
{
	pathnode_t *new, *tmp;

	if (!head || !str)
		return (NULL);
	new = malloc(sizeof(pathnode_t));
	if (!new)
	{
		perror("malloc");
		exit(1);
	}
	new->p = _strdup(str);
	new->next = NULL;

	tmp = *head;
	if (!(*head))
		return ((*head = new));
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (*head);
}

/**
 * find_e - find
 * @p: char *
 * Return: 1 0
 */

int find_e(char *p)
{
	char *s = p;

	if (!p)
		return (0);
	while (*s != '/')
	{
		if (!(*s))
			return (0);
		s++;
	}
	return (1);
}
