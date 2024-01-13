#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strdup(char *str);
char *concats(char *name, char *sep, char *value);

char **_split(char *str, const char *del);
void eXeqtor(char **argv);
void *_realloc(void *ptr, unsigned int old_s, unsigned int new_s);


extern char **environ;

/**
 * struct list_path - Linked list containing PATH directories
 * @dir: directory in path
 * @p: pointer to next node
 */
typedef struct PATH_list
{
	char *dir;
	struct PATH_list *p;
} PATH_list;


char *_getenv(const char *name);
PATH_list *add_node_end(PATH_list **head, char *str);
PATH_list *goto_path(char *path);
char *_chos(char *flnm, PATH_list *head);
void freeargv(char **arvg);
void free_list(PATH_list *head);

#endif
