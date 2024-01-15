#include "main.h"
/**
 * _split - a func to split string into tokens
 * @bf: buffer
 * Return: array of pointers to char
 */
char **_split(char *bf)
{
	int i = 0, cnt = 0;
	char *token = NULL, *tmp = NULL;
	char **tokens = NULL;

	if (!bf)
		return (NULL);

	tmp = _strdup(bf);
	token = strtok(tmp, DELIM);
	if (!token)
	{
		free(bf), bf = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}

	while (token)
	{
		cnt++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;

	tokens = malloc(sizeof(char *) * (cnt + 1));
	if (!tokens)
	{
		free(bf), bf = NULL;
		return (NULL);
	}
	token = strtok(bf, DELIM);
	while (token)
	{
		tokens[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	free(bf), bf = NULL;
	tokens[i] = NULL;
	return (tokens);
}
