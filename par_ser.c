#include "main.h"
/**
 * is_cmd - Determines if file is  executable command
 * @info: Info Struct
 * @path: File Path
 *
 * Return: On success 1, else 0
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - Duplicates Characters
 * @pathstr: String path
 * @start: Start Index
 * @stop: Stop Index
 *
 * Return: Buffer new ptr
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int w = 0, u = 0;

	for (u = 0, w = start; w < stop; w++)
		if (pathstr[w] != ':')
			buf[u++] = pathstr[w];
	buf[u] = 0;
	return (buf);
}

/**
 * find_path - Finds cmd in the string path
 * @info: Info Struct
 * @pathstr: String Path
 * @cmd: cmd to find
 *
 * Return: cmd path if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int w = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[w] || pathstr[w] == ':')
		{
			path = dup_chars(pathstr, curr_pos, w);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[w])
				break;
			curr_pos = w;
		}
		w++;
	}
	return (NULL);
}


