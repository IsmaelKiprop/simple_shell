#include "main.h"

/**
 **_strncpy - copy string
 *@dest: destination string to copy to
 *@src: string source 
 *@n: amount of char to  copy
 *Return: concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates 2 strings
 *@dest: first string
 *@src: second string
 *@n: amount of bytes to maximally use
 *Return: concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int w, j;
	char *s = dest;

	w = 0;
	j = 0;
	while (dest[w] != '\0')
		w++;
	while (src[j] != '\0' && j < n)
	{
		dest[w] = src[j];
		w++;
		j++;
	}
	if (j < n)
		dest[w] = '\0';
	return (s);
}

/**
 **_strchr - locate char in the string
 *@s: string to be parsed
 *@c: char to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

