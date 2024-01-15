#include "main.h"
/**
 * _getenv - gets global val
 * @name - var name
 * Return: string
 */
char *_getenv(char *envar)
{
	int i, Varlen;
	char *tmp, *key, *val, *env;

	i = 0;
	Varlen = _strlen(envar);
	while(environ[i])
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strncmp(envar, key, Varlen) == 0)
		{
			val = strtok(NULL, "\n");
			env = _strdup(val);
			free(tmp), tmp = NULL;
			return (env);
		}
		free(tmp), tmp = NULL;
		i++;
	}
	return (NULL);
}
