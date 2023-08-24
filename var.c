#include "main.h"
/**
 * is_chain - Test if current char in buffer is a chain delimeter
 * @info:  Par Struct
 * @buf: Char Buffer
 * @p: Address of buf
 *
 * Return: Success 1, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t x = *p;

	if (buf[x] == '|' && buf[x + 1] == '|')
	{
		buf[x] = 0;
		x++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[x] == '&' && buf[x + 1] == '&')
	{
		buf[x] = 0;
		x++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[x] == ';') /* found end  command */
	{
		buf[x] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = x;
	return (1);
}

/**
 * check_chain - Checks the entry point
 * @info: Parameter Struct
 * @buf: Buffer Char
 * @p: Address of current position
 * @i: Start position in buf
 * @len: Buf lenght
 *
 * Return: void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t x = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			x = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			x = len;
		}
	}

	*p = x;
}

/**
 * replace_alias - Replaces an aliases
 * @info:  Parameter Struct
 *
 * Return: once replaced return 1, else 0
 */
int replace_alias(info_t *info)
{
	int w;
	list_t *node;
	char *p;

	for (w = 0; w < 10; w++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - Replaces vars
 * @info: Parameter Struct
 *
 * Return: once replaced 1, else 0
 */
int replace_vars(info_t *info)
{
	int w = 0;
	list_t *node;

	for (w = 0; info->argv[w]; w++)
	{
		if (info->argv[w][0] != '$' || !info->argv[w][1])
			continue;

		if (!_strcmp(info->argv[w], "$?"))
		{
			replace_string(&(info->argv[w]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[w], "$$"))
		{
			replace_string(&(info->argv[w]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[w][1], '=');
		if (node)
		{
			replace_string(&(info->argv[w]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[w], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - Replaces String
 * @old: Address of old string
 * @new: New String
 *
 * Return:once replaced  1, else 0
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}










