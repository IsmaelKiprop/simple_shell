#include "main.h"
/**
 * _strlen - Returns length of a string
 * @s: string  length to check
 *
 * Return: Integer string lenght
 */
int _strlen(char *s)
{
	int w = 0;

	if (!s)
		return (0);

	while (*s++)
		w++;
	return (w);
}

/**
 * _strcmp - Performs  comparison of two strangs
 * @s1: First Strang
 * @s2: Second Strang
 *
 * Return:  Positive if s1 > s2, zero if s1 == s2 ,Negative if s1 < s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - Checks if needle starts with haystack
 * @haystack: String  Search
 * @needle: Substring
 *
 * Return: Address of next char  or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - Concatenate 2 strings
 * @dest: Destination buffer
 * @src: Buffer Source
 *
 * Return: Ptr
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
