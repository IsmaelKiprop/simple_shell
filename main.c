#include "main.h"
/**
 * interactivemode - If shell is in interactive mode, return true
 * @inf: Struct Address
 *
 * Return: Always 1 if interactive mode, 0 otherwise
 */
int interactivemode(passinf *inf)
{
	return (isatty(STDIN_FILENO) && inf->read_fd <= 2);
}

/**
 * is_delimiter - If character is a delimiter
 * @x: char check
 * @delim: delimiter string
 * Return: when true return 1, 0 if false
 */
int is_delimiter(char x, char *delim)
{
	while (*delim)
		if (*delim++ == x)
			return (1);
	return (0);
}

/**
 * is_alpha - alphabetic character to be checked
 * @x: character to check
 * Return: if x is alphabetic return 1, 0 otherwise
 */
int is_alpha(int x)
{
	if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * str_int - converts a string to an integer
 * @x: string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int str_int(char *x)
{
	int w, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (w = 0; x[w] != '\0' && flag != 2; x++)
	{
		if (w[x] == '-')
			sign *= -1;

		if (w[x] >= '0' && w[x] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (w[x] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

