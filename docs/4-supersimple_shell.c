#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char **line = NULL;
	pid_t MyPID;
	pid_t GetPID;

	while (1)
	{
		char *bf;
		size_t len;

		MyPID = fork();
		if (MyPID == 0)
			return (MyPID);
		else
		{
			perror("Error");
			return (-1);
		}
        	printf("$ ");
		getline(&bf, &len, stdin);

		if (bf == NULL)
			wait(&status);

		line = &bf;
		wait(MyPID, &status, 0);
	}
	return (0);
}
