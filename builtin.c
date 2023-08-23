#include "main.h"
/**
 * my_exit - Shell exit
 * @inf: Structure containing potential arguments.
 * constant func prototype.
 * Return: Exits with a exit status
 * (0) if info.argv[0] != "exit"
 */
int my_exit(passinf *inf)
{
	int exitcheck;

	if (inf->argv[1]) /* If there is an exit arguement */
	{
		exitcheck = err_str(inf->argv[1]);
		if (exitcheck == -1)
		{
			inf->status = 2;
			print_errors(inf, "Illegal number: ");
			e_puts(inf->argv[1]);
			e_putchar('\n');
			return (1);
		}
		inf->err_numb = err_str(inf->argv[1]);
		return (-2);
	}
	inf->err_numb = -1;
	return (-2);
}

/**
 * my_cd - Changes the current directory of the process
 * @inf: Structure containing potential arguments.To maintain
 * constant function prototype.
 * Return: Always 0 Success
 */
int my_cd(passinf *inf)
{
	char *x, *dir, buffer[1024];
	int chdir_ret;

	x = getcwd(buffer, 1024);
	if (!x)
		e_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!inf->argv[1])
	{
		dir = get_env(inf, "HOME=");
		if (!dir)
			chdir_ret =
				chdir((dir = get_env(inf, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (strcmp(inf->argv[1], "-") == 0)
	{
		if (!get_env(inf, "OLDPWD="))
		{
			e_puts(x);
			e_putchar('\n');
			return (1);
		}
		e_puts(get_env(inf, "OLDPWD=")), e_putchar('\n');
		chdir_ret =
			chdir((dir = get_env(inf, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(inf->argv[1]);
	if (chdir_ret == -1)
	{
		print_errors(inf, "can't cd to ");
		e_puts(inf->argv[1]), e_putchar('\n');
	}
	else
	{
		set_env(inf, "OLDPWD", get_env(inf, "PWD="));
		set_env(inf, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * my_help - Changes the current directory of the process
 * @inf: Structure containing potential arguments.To maintain
 * constant function prototype.
 * Return: Always 0 Success
 */
int my_help(passinf *inf)
{
	char **arg_array;

	arg_array = inf->argv;
	e_puts("help call works. Function not yet implemented \n");
	if (0)
		e_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}



