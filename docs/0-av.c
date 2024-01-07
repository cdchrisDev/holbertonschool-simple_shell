#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
int main(int ac, char **av)
{
	int i = 1;
	(void)ac;

	while (av[i++] != NULL)
		printf("%s ", av[i]);

	putchar('\n');
}
