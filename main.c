#include "main.h"
/**
 * interactive - returns true if the shell is in the interactive mode
 * @info: struct address
 *
 * Return: 1 if in the interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if the character is delimeter
 * @c: char to be check
 * @delim: the delimeter string
 * Return: 1 if it is true, and 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic characters
 * @c: character to  be input
 * Return: 1 if c is alphabetic, and 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts the string to integer
 * @x: string to convert
 * Return: 0 if there is no numbers in the  string, or converted number otherwise
 */

int _atoi(char *x)
{
	int w, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (w = 0; x[w] != '\0' && flag != 2; w++)
	{
		if (x[w] == '-')
			sign *= -1;

		if (x[w] >= '0' && x[w] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (x[w] - '0');
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


