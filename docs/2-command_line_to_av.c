#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int ac, char **av)
{
	char str = NULL;
	char delim = NULL;
	size_t n;

	delim = " ";

	getline(&str, &n, stdin);
	strtok(str, delim);

	printf("%s\n", str);
}
