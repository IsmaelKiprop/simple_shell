#include "main.h"
/**
 * _memset - Fills memory with  constant byte
 * @s: Ptr to  memory area
 * @b: byte to fill *s with
 * @n: Amount of bytes
 * Return: Ptr to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int w;

	for (w = 0; w < n; w++)
		s[w] = b;
	return (s);
}

/**
 * ffree - Frees  string of strings
 * @pp: String of Strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - Reallocates  block of memory
 * @ptr: ptr to previous block
 * @old_size: Byte size
 * @new_size: Byte of new block
 *
 * Return: ptr to block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}


