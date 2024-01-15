#include "main.h"
/**
 * _getline - func that save input user
 * Return: a string
 */
char *_getline(void)
{
	char *bf = NULL;
	size_t bf_size = 0;
	ssize_t char_r = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "($) ", 2);
	char_r = getline(&bf, &bf_size, stdin);
	if (char_r == -1)
	{
		free(bf);
		bf = NULL;
		return (NULL);
	}
	return (bf);
}
