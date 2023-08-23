#include "main.h"
/**
 * get_environ - Returns string array copy of our environ
 * @inf: Structure containing potential arguments.
 * Return: Always 0 Success
 */
char **get_environ(passinf *inf)
{
	if (!inf->environ || inf->env_changed)
	{
		inf->environ = list_to_strings(inf->env);
		inf->env_changed = 0;
	}

	return (inf->environ);
}

/**
 * unset_env - Remove environment variable
 * @inf: Structure containing potential arguments.
 *  Return: 1 when deleted, 0 otherwise
 * @var: String env var property
 */
int unset_env(passinf *inf, char *var)
{
	list_str *node = inf->env;
	size_t w = 0;
	char *u;

	if (!node || !var)
		return (0);

	while (node)
	{
		u = starts_with(node->str, var);
		if (u && *u == '=')
		{
			inf->env_changed = delete_node_at_index(&(inf->env), w);
			w = 0;
			node = inf->env;
			continue;
		}
		node = node->next;
		w++;
	}
	return (inf->env_changed);
}

/**
 * set_env - Initialize a new environment variable
 * @inf: Structure containing potential arguments.
 * @var: String env var property
 * @value: String env var value
 *  Return: Always 0 Success
 */
int set_env(passinf *inf, char *var, char *value)
{
	char *buf = NULL;
	list_str *node;
	char *u;

	if (!var || !value)
		return (0);

	buf = malloc(strlen(var) + strlen(value) + 2);
	if (!buf)
		return (1);
	strcpy(buf, var);
	strcat(buf, "=");
	strcat(buf, value);
	node = inf->env;
	while (node)
	{
		u = starts_with(node->str, var);
		if (u && *u == '=')
		{
			free(node->str);
			node->str = buf;
			inf->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(inf->env), buf, 0);
	free(buf);
	inf->env_changed = 1;
	return (0);
}

