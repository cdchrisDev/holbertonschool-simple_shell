#include "main.h"
/**
 * main - entry point
 * @ac: size of av
 * @av: array of ac
 * Return: returns (0) on success
 */
int main(int ac, char **av)
{
	int i = 0;
	char *bf = NULL, **cmd = NULL;
	(void)ac;

	while (1)
	{
		bf = _getline();
		if (bf == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		i++;

		cmd = _split(bf);
		if (!cmd)
			continue;
		else
			eXeqtor(cmd, av, i);
	}
}
