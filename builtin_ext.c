#include "main.h"
/**
 * my_alias - mimics the alias builtin (man alias)
 * @inf: Structure containing potential arguments.
 *  Return: Always 0 SUCCESS
 */
int my_alias(passinf *inf)
{
	int x = 0;
	char *w = NULL;
	list_str *node = NULL;

	if (inf->argc == 1)
	{
		node = inf->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (x = 1; inf->argv[x]; x++)
	{
		w = str_chr(inf->argv[x], '=');
		if (w)
			set_alias(inf, inf->argv[x]);
		else
			print_alias(node_starts_with(inf->alias, inf->argv[x], '='));
	}

	return (0);
}

/**
 * my_history - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0 Success
 */
int my_history(passinf *inf)
{
	print_list_str(inf->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @inf: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(passinf *inf, char *str)
{
	char *w, x;
	int ret;

	w = strchr(str, '=');
	if (!w)
		return (1);
	x = *w;
	*w = 0;
	ret = delete_node_at_index(&(inf->alias),
		get_node_index(inf->alias, node_starts_with(inf->alias, str, -1)));
	*w = x;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @inf: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(passinf *inf, char *str)
{
	char *w;

	w = strchr(str, '=');
	if (!w)
		return (1);
	if (!*++w)
		return (unset_alias(inf, str));

	unset_alias(inf, str);
	return (add_node_end(&(inf->alias), str, 0) == NULL);
}

/**
 * print_alias - Prints an alias string
 * @node: alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_str *node)
{
	char *w = NULL, *x = NULL;

	if (node)
	{
		w = strchr(node->str, '=');
		for (x = node->str; x <= w; x++)
		e_putchar(*x);
		e_putchar('\'');
		e_puts(w + 1);
		e_putchar('\n');
		return (0);
	}
}






