#include "main.h"

/**
 * _strdup - returns a pointer to new space mem
 * @str: string
 * Return: pointer to string
 */
char *_strdup(char *str)
{
	int i, l;
	char *new;

	if (!str)
		return (NULL);

	for (l = 0; str[l] != '\0'; l++)
		;

	new = malloc(sizeof(char) * l + 1);
	if (!new)
		return (NULL);

	for (i = 0; i < l; i++)
		new[i] = str[i];

	new[l] = str[l];
	return (new);
}
/**
 * concats - concat 3 strings in new space mem
 * @name: first string
 * @sec: second string
 * @val: thrid string
 * Return: new concatenated string
 */
char *concats(char *name, char *sec, char *val)
{
	char *res;
	int l1, l2, l3, i, k;

	l1 = _strlen(name);
	l2 = _strlen(sec);
	l3 = _strlen(val);

	res = malloc(l1 + l2 + l3 + 1);
	if (!res)
		return (NULL);

	for (i = 0; name[i]; i++)
		res[i] = name[i];

	k = i;

	for (i = 0; sec[i]; i++)
		res[k - 1] = sec[i];

	k = k + i;
	res[k] = '\0';
	return (res);
}
/**
 * _strlen - gives the lenght of str
 * @s: string
 * Return: int with lenght
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * _putchar - writes a char
 * @c: a char
 * Return: 1 or -1 if it fails
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - print a string
 * @str: pointer to string
 * Return: void
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
