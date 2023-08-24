#include "main.h"

/**
 * list_len - Determines length of linked list
 * @h: Ptr to next node
 *
 * Return:  size
 */
size_t list_len(const list_t *h)
{
	size_t w = 0;

	while (h)
	{
		h = h->next;
		w++;
	}
	return (w);
}

/**
 * list_to_strings - Returns array of strings of the list->str
 * @head: ptr to next node
 *
 * Return: strings Arrays
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t w = list_len(head), x;
	char **strs;
	char *str;

	if (!head || !w)
		return (NULL);
	strs = malloc(sizeof(char *) * (w + 1));
	if (!strs)
		return (NULL);
	for (w = 0; node; node = node->next, w++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (x = 0; x < w; x++)
				free(strs[x]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[w] = str;
	}
	strs[w] = NULL;
	return (strs);
}


/**
 * print_list - Prints  elements of a list_t linked list
 * @h: ptr to next node
 *
 * Return:list size
 */
size_t print_list(const list_t *h)
{
	size_t w = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		w++;
	}
	return (w);
}

/**
 * node_starts_with - Returns node  with prefix
 * @node: Ptr to list head
 * @prefix: String  match
 * @c: next char after prefix to match
 *
 * Return: Null or match node
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - Get index of a node
 * @head: Ptr to list head
 * @node: Ptr to the node
 *
 * Return: -1 or Index node
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t w = 0;

	while (head)
	{
		if (head == node)
			return (w);
		head = head->next;
		w++;
	}
	return (-1);
}
