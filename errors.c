#include "main.h"

/**
 * e_puts - Prints an input string
 * @str: String to be printed
 *
 * Return: Nothing
 */
void e_puts(char *str)
{
	int w = 0;

	if (!str)
		return;
	while (str[w] != '\0')
	{
		e_putchar(str[w]);
		w++;
	}
}

/**
 * e_putchar - writes the character x to stderr
 * @x: Character to print
 *
 * Return: 1 on Success
 * On error, Return -1, and errno is set appropriately.
 */
int e_putchar(char x)
{
	static int w;
	static char buf[WRITE_BUFF_SIZE];

	if (x == BUFF_FLUSH || w >= WRITE_BUFF_SIZE)
	{
		write(2, buf, w);
		w = 0;
	}
	if (x != BUFF_FLUSH)
		buf[w++] = x;
	return (1);
}

/**
 * put_fd - writes character x to given fd
 * @x: Character to print
 * @fd: The filedescriptor to write to
 *
 * Return: 1 on Success
 * On error, return -1, and errno is set appropriately.
 */
int put_fd(char x, int fd)
{
	static int w;
	static char buf[WRITE_BUFF_SIZE];

	if (x == BUFF_FLUSH || w >= WRITE_BUFF_SIZE)
	{
		write(fd, buf, w);
		w = 0;
	}
	if (x != BUFF_FLUSH)
		buf[w++] = x;
	return (1);
}

/**
 * puts_fd - prints an input string
 * @str: String to be printed
 * @fd: filedescriptor to write to
 *
 * Return: number of chars put
 */
int puts_fd(char *str, int fd)
{
	int w = 0;

	if (!str)
		return (0);
	while (*str)
	{
		w += put_fd(*str++, fd);
	}
	return (w);
}
