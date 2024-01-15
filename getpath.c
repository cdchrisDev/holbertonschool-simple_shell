#include "main.h"
/**
 * get_PATH - a func to get path of command line
 * @cmd: string
 * Return: command or NULL
 */
char *get_PATH(char *cmd)
{
	char *path = NULL, *token = NULL, *full_cmd = NULL;
	struct stat st;
	int i;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}
	path = _getenv("PATH");
	if (!path)
		return (NULL);

	token = strtok(path, ":");
	while (token != NULL)
	{
		full_cmd = malloc(_strlen(token) + _strlen(cmd) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, token);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, cmd);
			if (stat(full_cmd, &st) == 0)
			{
				free(path), path = NULL;
				return (full_cmd);
			}
			free(full_cmd), full_cmd = NULL;
			token = strtok(NULL, ":");
		}
	}
	free(path), path = NULL;
	return (NULL);
}
