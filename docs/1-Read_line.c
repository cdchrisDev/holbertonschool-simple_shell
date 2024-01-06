#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *bf = NULL;
	size_t len = 0;

	printf("$ ");
	getline(&bf, &len, stdin);

	printf("your input is: %s\n and the size is %ld\n", bf, len);

	free(bf);
}
