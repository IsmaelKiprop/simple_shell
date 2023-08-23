#include "main.h"
/**
 * clear_inf - initializes passinf struct
 * @inf: struct address
 */
void clear_inf(passinf *inf)
{
	inf->arg = NULL;
	inf->argv = NULL;
	inf->path = NULL;
	inf->argc = 0;
}

/**
 * set_inf - initializes passinfo struct
 * @inf: struct address
 * @av: argument vector
 */
void set_inf(passinf *inf, char **av)
{
int w = 0;
char *token;

inf->f_name = av[0];
if (inf->arg)
{
/* Count the number of tokens */
for (token = strtok(inf->arg, " \t"); token; token = strtok(NULL, " \t"))
{
w++;
}

/* Allocate memory for inf->argv */
inf->argv = (char **)malloc(sizeof(char *) * (w + 1)); /* +1 for NULL */
if (inf->argv)
{
int i = 0;
char *token;

/* Copy tokens to inf->argv */
token = strtok(inf->arg, " \t");
while (token)
{
inf->argv[i] = strdup(token);
token = strtok(NULL, " \t");
i++;
}
inf->argv[i] = NULL;

inf->argc = w;

replace_alias(inf);
replace_vars(inf);
}
}
}

/**
 * free_inf - frees passinf struct fields
 * @inf: Struct address
 * @all: true if freeing all fields.
 */
void free_inf(passinf *inf, int all)
{
	ffree(inf->argv);
	inf->argv = NULL;
	inf->path = NULL;
	if (all)
	{
		if (!inf->cmd_buf)
			free(inf->arg);
		if (inf->env)
			free_list(&(inf->env));
		if (inf->history)
			free_list(&(inf->history));
		if (inf->alias)
			free_list(&(inf->alias));
		ffree(inf->environ);
			inf->environ = NULL;
		bfree((void **)inf->cmd_buf);
		if (inf->read_fd > 2)
			close(inf->read_fd);
		e_putchar(BUFF_FLUSH);
	}
}
