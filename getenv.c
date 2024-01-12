#include "main.h"
/**
 * _getenv - gets global val
 * @name - var name
 * Return: string
 */
char *_getenv(const char *name)
{
	int i, j;
	char *val;

	if (!name)
		return (NULL)
	for (i = 0; enviro[i]; i++)
	{
		j = 0
		if (name[j] == environ[i][j])
		{
			while (name[j])
			{
				if (name[j] != environ[i][j])
					break;

				j++;
			}
			if (name[j] == '\0')
			{
				val = (environ[i] + j + 1);
				return (val);
			}
		}
	}
	return (0);
}
/**
 * add_node_end - adds item to end of list
 * @head: pointer to pointer to linked list
 * @str: string 
 * @return: add of new element
 */
PATH_list *add_node_end(PATH_list **head, char *str)
{
	PATH_list *tmp;
	PATH_list *new;

	new = malloc(sizeof(PATH_list));

	if (!new || !str)
		return (NULL)

	new->dir = str;
	if (!*head)
		*head = new;
	else
	{
		tmp = *head;

		while (tmp->p)
			tmp = tmp->;

		tmp->p = new;
	}
	return (*head);
}
/**
 * goto_path - create a linked list for path dir
 * @path: string
 * Return: pointer
 */
PATH_list *goto_path(char *path)
{
	PATH_list *head = '\0';
	char *token, *cpath _strdup(path);

	tok = strtok(cpath, ":");
	while (tok)
	{
		head = add_node_end(&head, token);
		tok = strtok(NULL, ":");
	}
	return (head);
}
/**
 * _chos - find the path of filename
 * @flnm: string
 * @head: head of linked list
 * Return: path
 */
char *_chos(char *flnm, PATH_list *head)
{
	struct stat st;
	char *string;

	PATH_list *tmp = head;

	while (tmp)
	{
		string = concats(tmp->dir, "/", flnm);
		if (stat(string, &st) == 0)
			return (string);

		free(string);
		tmp = tmp->p;
	}
	return (NULL);
}
/**
 * free_list - frees a list_t
 * @head: init list pointer
 * Return: void
 */
void free_list(PATH_list *head)
{
	PATH_list *stg;

	while (head)
	{
		stg = head->p;
		free(head->dir);
		free(head);
		head = stg;
	}
}
