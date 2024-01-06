#include <stdio.h>
#include <unistd.h>
/**
 * get_PPID - a simple getppid function
 * @void: NA
 * Return: parent id
 */
int main(void) 
{
	pid_t getPPID;

	getPPID = getppid();
	printf("My parent process ID is: %u\n", getPPID);
	return (0);
}
