#include "main.h"

/**
 *strn_cpy - copies a string
 *@destn: destination string to be copied to
 *@src_strn: source string
 *@x: Amount of characters to be copied
 *Return: Concatenated string
 */
char *strn_cpy(char *destn, char *src_strn, int x)
{
	int w, z;
	char *u = destn;

	w = 0;
	while (src_strn[w] != '\0' && w < x - 1)
	{
		destn[w] = src_strn[w];
		w++;
	}
	if (w < x)
	{
		z = w;
		while (z < x)
		{
			destn[z] = '\0';
			z++;
		}
	}
	return (u);
}

/**
 *strn_cat - concatenates two strings
 *@destn: the first string
 *@src_strn: the second string
 *@x: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *strn_cat(char *destn, char *src_strn, int x)
{
	int w, z;
	char *u = destn;

	w = 0;
	z = 0;
	while (destn[w] != '\0')
		w++;
	while (src_strn[z] != '\0' && z < x)
	{
		destn[w] = src_strn[z];
		w++;
		z++;
	}
	if (z < x)
		destn[w] = '\0';
	return (u);
}

/**
 *str_chr - locate character in a string
 *@s: String to be parsed
 *@x: Character to look for
 *Return: (s) a pointer to memory area s
 */
char *str_chr(char *s, char x)
{
	do {
		if (*s == x)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

