#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(void)
{
	char c[] = "Hola como estas";
	char d[] = " ";
	char *p;

	p = strtok(c, d);
	
	while (p != NULL)
	{
		printf("%s", p);
		p = strtok (NULL, d);
	}

	putchar('\n');
}
