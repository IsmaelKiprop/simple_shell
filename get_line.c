#include "main.h"
/**
 * input_buf - buffers chained commands
 * @inf: Parameter struct
 * @buf: Address of buffer
 * @lent: Address of len var
 *
 * Return: bytes read
 */
ssize_t input_buf(passinf *inf, char **buf, size_t *lent)
{
	ssize_t x = 0;
	size_t lent_u = 0;

	if (!*lent) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)inf->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigint_Handler);
#if USE_GETLINE
		x = getline(buf, &lent_u, stdin);
#else
		x = get_line(inf, buf, &lent_u);
#endif
		if (x > 0)
		{
			if ((*buf)[x - 1] == '\n')
			{
				(*buf)[x - 1] = '\0';
				x--;
			}
			inf->line_count_flag = 1;
			remove_comments(*buf);
			build_history_list(inf, *buf, inf->hist_count++);
			{
				*lent = x;
				inf->cmd_buf = buf;
			}
		}
	}
	return (x);
}

/**
 * get_input - Get a line without the newline
 * @inf: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(passinf *inf)
{
	static char *buf;
	static size_t w, z, lent;
	ssize_t x = 0;
	char **buf_u = &(inf->arg), *u;

	e_putchar(BUFF_FLUSH);
	x = input_buf(inf, &buf, &lent);
	if (x == -1)
		return (-1);
	if (lent)
	{
		z = w;
		u = buf + w;

		check_chain(inf, buf, &z, w, lent);
		while (z < lent)
		{
			if (is_chain(inf, buf, &z))
				break;
			z++;
		}

		w = z + 1;
		if (w >= lent)
		{
			w = lent = 0;
			inf->cmd_buf_type = CMD_NORM;
		}

		*buf_u = u;
		return (strlen(u));
	}

	*buf_u = buf;
	return (x);
}

/**
 * read_buf - Reads buffer
 * @inf: Parameter struct
 * @buf: buffer
 * @w: size
 *
 * Return: x
 */
ssize_t read_buf(passinf *inf, char *buf, size_t *w)
{
	ssize_t x = 0;

	if (*w)
		return (0);
	x = read(inf->read_fd, buf, READ_BUFF_SIZE);
	if (x >= 0)
		*w = x;
	return (x);
}

/**
 * get_line - Gets next line of input from STDIN
 * @inf: Parameter struct
 * @ptr: Address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: x
 */
int get_line(passinf *inf, char **ptr, size_t *length)
{
	static char buf[READ_BUFF_SIZE];
	static size_t w, lent;
	size_t t;
	ssize_t r = 0, x = 0;
	char *u = NULL, *new_u = NULL, *o;

	u = *ptr;
	if (u && length)
		x = *length;
	if (w == lent)
		w = lent = 0;

	r = read_buf(inf, buf, &lent);
	if (r == -1 || (r == 0 && lent == 0))
		return (-1);

	o = strchr(buf + w, '\n');
	t = o ? 1 + (unsigned int)(o - buf) : lent;
	new_u = _realloc(u, x, x ? x + t : t + 1);
	if (!new_u)
		return (u ? free(u), -1 : -1);

	if (x)
		strncat(new_u, buf + w, t - w);
	else
		strncpy(new_u, buf + w, t - w + 1);

	x += t - w;
	w = t;
	u = new_u;

	if (length)
		*length = x;
	*ptr = u;
	return (x);
}

/**
 * sigint_Handler - blocks ctrl-C
 * @sig_numb: the signal number
 *
 * Return: void
 */
void sigint_Handler(__attribute__((unused))int sig_numb)
{
	e_puts("\n");
	e_puts("$ ");
	e_putchar(BUFF_FLUSH);
}

