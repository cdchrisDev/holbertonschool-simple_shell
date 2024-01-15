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
#include <fcntl.h>

#define DELIM " \t\n"
extern char **environ;

/* FUNCTIONS */
char *_getline(void);
char **_split(char *bf);
int eXeqtor(char **cmd, char **av, int i);
char *_getenv(char *envar);
char *get_PATH(char *cmd);

/* STR MANIPULATION */
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
int _strncmp(const char *s1, const char *s2, unsigned int n);
char *_strdup(char *src);
char *_strcat(char *dest, const char *src);

/* Help */
void _free2dArr(char **arr);
void error_handle(char *name, char *cmd, int indx);
char *_itoa(int num);
void str_rev(char *str, int len);

#endif
