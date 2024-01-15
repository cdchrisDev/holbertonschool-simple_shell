#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
	pid_t MyPid;
	pid_t getid;
	int status;

	getid = getpid(); /* tell me who processes */
	printf("before fork I was one: I identify as %u, and that means chris.\n", getid);
	MyPid = fork(); /* new process */
	if (MyPid == -1)
	{	/* check new process return success*/
		perror("Error:");
		return (-1);
	}
	/* checking process status*/
	getid = getpid();
	if (MyPid == 0)
	{
		printf("After fork I'm another,now %u. I grew up so much I became the child.\n", getid);

                char *argv[] = { "/bin/ls", "-l", "/tmp/", NULL };
		char *newarg = argv[0];

                if (argc != 2)
                {
                        fprintf(stderr, "Usage %s <file-to-exec>\n", argv[0]);
                        exit(EXIT_FAILURE);
                }

		execve(newarg, argv, NULL);
	}
	else if (MyPid != 0)
		printf("I returned to the father, cuz I'm chris again (%u) \n", getid);

	else
	{
		fork();
		printf("I'm your father\n");
		wait(&status);
	}
	return (1);
}
