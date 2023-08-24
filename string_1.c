#include "main.h"
/**
 * _strcpy - Copy String
 * @dest: Destination
 * @src: Source
 *
 * Return: Destination Ptr
 */
char *_strcpy(char *dest, char *src)
{
	int w = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[w])
	{
		dest[w] = src[w];
		w++;
	}
	dest[w] = 0;
	return (dest);
}

/**
 * _strdup - Duplicates String
 * @str: String Duplicate
 *
 * Return: Duplicated string ptr
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _puts - Print input string
 * @str: Printed string
 *
 * Return: Null
 */
void _puts(char *str)
{
	int w = 0;

	if (!str)
		return;
	while (str[w] != '\0')
	{
		_putchar(str[w]);
		w++;
	}
}

/**
 * _putchar - Writes  char c to stdout
 * @c:  char to print
 *
 * Return: 1 0n success
 * -1 on error is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int w;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || w >= WRITE_BUF_SIZE)
	{
		write(1, buf, w);
		w = 0;
	}
	if (c != BUF_FLUSH)
		buf[w++] = c;
	return (1);
}
