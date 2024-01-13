#include "main.h"
/**
 * sig_handler - check for Ctrl C
 * @sig_n: int
 * Return: void
 */
void sig_handler(int sig_n)
{
	if (sig_n == SIGINT)
		_puts("\n#cisfun$ ");
}
/**
 * _EOF - handles the End of FIle
 * @len: lenght of getline
 * @bf: buffer
 * Return: void
 */
void _EOF(int len, char *bff)
{
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(bff);
		}
		exit(0);
	}
}
/**
 * _issatty - if terminal
 */
void _issatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#cisfun$ ");
}
/**
 * main - shell
 * Return: 0
 */
int main(void)
{
	ssize_t len = 0;
	char *bffer = NULL, *val, *PATH_name, **argv;
	size_t size = 0;
	PATH_list *head = '\0';

	signal(SIGINT, sig_handler);
	while (len != EOF)
	{
		_issatty();
		len = getline(&bffer, &size, stdin);
		_EOF(len, bffer);
		argv = _split(bffer, " \n");
		if (!argv || argv[0])
			eXeqtor(argv);
		else
		{
			val = _getenv("PATH");
			head = goto_path(val);
			PATH_name = _chos(argv[0], head);

			if (!PATH_name)
				eXeqtor(argv);

			else if (PATH_name)
			{
				free(argv[0]);
				argv[0] = PATH_name;
				eXeqtor(argv);
			}
		}
	}
	free_list(head);
	freeargv(argv);
	free(bffer);
	return (0);
}
