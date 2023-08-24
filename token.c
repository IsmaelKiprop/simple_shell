#include "main.h"
/**
 * **strtow - Splits string into words
 * @str: String input
 * @d: String Delimiter
 * Return: Ptr to  array of strings, else NULL on failure
 */

char **strtow(char *str, char *d)
{
	int w, x, u, n, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (w = 0; str[w] != '\0'; w++)
		if (!is_delim(str[w], d) && (is_delim(str[w + 1], d) || !str[w + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (w = 0, x = 0; x < numwords; x++)
	{
		while (is_delim(str[w], d))
			w++;
		u = 0;
		while (!is_delim(str[w + u], d) && str[w + u])
			u++;
		s[x] = malloc((u + 1) * sizeof(char));
		if (!s[x])
		{
			for (u = 0; u < x; u++)
				free(s[u]);
			free(s);
			return (NULL);
		}
		for (n = 0; n < u; n++)
			s[x][n] = str[w++];
		s[x][n] = 0;
	}
	s[x] = NULL;
	return (s);
}

/**
 * **strtow2 - Split string into words
 * @str: String Input
 * @d: Delimeter
 * Return: Ptr to  array of strings, else NULL on failure
 */
char **strtow2(char *str, char d)
{
	int w, x, u, n, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (w = 0; str[w] != '\0'; w++)
		if ((str[w] != d && str[w + 1] == d) ||
				    (str[w] != d && !str[w + 1]) || str[w + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (w = 0, w = 0; w < numwords; w++)
	{
		while (str[w] == d && str[w] != d)
			w++;
		u = 0;
		while (str[w + u] != d && str[w + u] && str[w + u] != d)
			u++;
		s[x] = malloc((u + 1) * sizeof(char));
		if (!s[x])
		{
			for (u = 0; u < x; u++)
				free(s[u]);
			free(s);
			return (NULL);
		}
		for (n = 0; n < u; n++)
			s[x][n] = str[w++];
		s[x][n] = 0;
	}
	s[x] = NULL;
	return (s);
}
