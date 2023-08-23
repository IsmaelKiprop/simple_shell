#include "main.h"

/**
 * my_env - Prints current environment
 * @inf: Structure holding potential arguments.
 * Return: Always 0 Success
 */
int my_env(passinf *inf)
{
	print_list_str(inf->env);
	return (0);
}

/**
 * get_env - Gets value of environ variable
 * @inf: Structure holding potential arguments.
 * @name_var: env var name
 *
 * Return: the value
 */
char *get_env(passinf *inf, const char *name_var)
{
	list_str *node = inf->env;
	char *w;

	while (node)
	{
		w = starts_with(node->str, name_var);
		if (w && *w)
			return (w);
		node = node->next;
	}
	return (NULL);
}

/**
 * my_setenv - Initialize new environment variable.
 * @inf: Structure containing potential arguments.
 *  Return: Always 0 Sucess
 */
int my_setenv(passinf *inf)
{
	if (inf->argc != 3)
	{
		e_puts("Incorrect number of arguements\n");
		return (1);
	}
	if (set_env(inf, inf->argv[1], inf->argv[2]))
		return (0);
	return (1);
}

/**
 * my_unsetenv - Remove environment variable
 * @inf: Structure containing potential arguments.
 * Return: Always 0 Success
 */
int my_unsetenv(passinf *inf)
{
	int x;

	if (inf->argc == 1)
	{
		e_puts("Too few arguements.\n");
		return (1);
	}
	for (x = 1; x <= inf->argc; x++)
		unset_env(inf, inf->argv[x]);

	return (0);
}

/**
 * populate_env_list - Populates env linked list
 * @inf: Structure containing potential arguments.
 * Return: Always 0 Success
 */
int populate_env_list(passinf *inf)
{
	list_str *node = NULL;
	size_t x;

	for (x = 0; environ[x]; x++)
		add_node_end(&node, environ[x], 0);
	inf->env = node;
	return (0);
}

