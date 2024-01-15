#include "main.h"
/**
 * eXeqtor - Execute a command
 * @cmd: command args
 * @av: args
 * @i: index of command
 * Return: exit status of the command
 */
int eXeqtor(char **cmd, char **av, int i)
{
	pid_t pid;
	int status;
	char *full_cmd;

	full_cmd = get_PATH(cmd[0]);
	pid = fork();
	if (!full_cmd)
	{
		error_handle(av[0], cmd[0], i);
		_free2dArr(cmd);
		return (127);
	}
	if (pid == 0)
	{
		if (execve(full_cmd, cmd, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			_free2dArr(cmd);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		_free2dArr(cmd);
		free(full_cmd);
		full_cmd = NULL;
	}
	return (0);
}
