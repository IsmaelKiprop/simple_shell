#include "main.h"

/**
 * err_str - Converts a string to an integer
 * @x: String to be converted
 * Return: If no numbers in string return 0, otherwise return -1
 *
 */
int err_str(char *x)
{
	int w = 0;
	unsigned long int result = 0;

	if (*x == '+')
		x++;
	for (w = 0;  x[w] != '\0'; w++)
	{
		if (x[w] >= '0' && x[w] <= '9')
		{
			result *= 10;
			result += (x[w] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_errors - Prints error messages
 * @inf: Parameter and return inf struct
 * @iss: String holding specified error type
 * Return: If no numbers in string return 0, otherwise return -1
 */
void print_errors(passinf *inf, char *iss)
{
	e_puts(inf->f_name);
	e_puts(": ");
	print_d(inf->line_count, STDERR_FILENO);
	e_puts(": ");
	e_puts(inf->argv[0]);
	e_puts(": ");
	e_puts(iss);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = e_putchar;
	int x, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = e_putchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (x = 1000000000; x > 1; x /= 10)
	{
		if (_abs_ / x)
		{
			__putchar('0' + current / x);
			count++;
		}
		current %= x;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - replaces first instance of '#' with '\0'
 * @buf: Address of the string to modify
 *
 * Return: Always 0 Success;
 */
void remove_comments(char *buf)
{
	int w;

	for (w = 0; buf[w] != '\0'; w++)
		if (buf[w] == '#' && (!w || buf[w - 1] == ' '))
		{
			buf[w] = '\0';
			break;
		}
}

