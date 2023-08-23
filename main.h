#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* 1 if using system getline() */
#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

/* command chaining */
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3
#define CMD_NORM	0

/* convert_number() */
#define USE_GETLINE 0
#define USE_STRTOK 0

/* Read/Write Buffers */
#define READ_BUFF_SIZE 1024
#define WRITE_BUFF_SIZE 1024
#define BUFF_FLUSH -1

#define CONVERT_UNSIGNED 1
#define CONVERT_LOWERCASE 2


extern char **environ;


/**
 * struct liststr - Singly linked list
 * @num: number field
 * @str: String
 * @next: Points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_str;

/**
 * @f_name: program filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @history: history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @read_fd: the fd from which to read line input
 * @hist_count: history line number count
 * struct passinf - contains pseudo-arguements to pass into a function,
 * allowing uniform prototype for function pointer struct
 * @arg: string generated from getline containing arguements
 * @argv:array of strings generated from arg
 * @path: string path for the current command
 * @argc: argument count
 * @line_count: error count
 * @err_numb: error code for exit()
 * @line_count_flag: if on count this line of input
 */
typedef struct passinf
{
	int err_numb;
    	int line_count_flag;
    	char *f_name;
    	list_str *env;
    	list_str *history;
    	list_str *alias;
    	char **environ;
    	int env_changed;
    	int status;
    	char **cmd_buf;
    	int cmd_buf_type;
    	int read_fd;
    	int hist_count;
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
} passinf;

#define INFO { \
    .f_name = NULL, \
    .env = NULL, \
    .environ = NULL, \
    .history = NULL, \
    .alias = NULL, \
    .env_changed = 0, \
    .status = 0, \
    .cmd_buf = NULL, \
    .cmd_buf_type = 0, \
    .read_fd = 0, \
    .hist_count = 0, \
    .arg = NULL, \
    .argv = NULL, \
    .path = NULL, \
    .argc = 0, \
    .line_count = 0, \
    .err_numb = 0, \
    .line_count_flag = 0 \
}


/**
 * struct builtin - contains a builtin string and related function
 * @type: builtin command flag
 * @func: function
 */
typedef struct builtin
{
	char *type;
	int (*func)(passinf *);
} builtin_table;

/* main.c */
int interactivemode(passinf *);
int is_delimiter(char, char *);
int is_alpha(int);
int str_int(char *);

/* builtin.c */
int my_exit(passinf *);
int my_cd(passinf *);
int my_help(passinf *);

/* builtin_ext.c*/
int my_history(passinf *inf);
int my_alias(passinf *inf);
int unset_alias(passinf *inf, char *str);
int set_alias(passinf *inf, char *str);
int print_alias(list_str *node);list_str *node_starts_with(list_str *list, const char *prefix, char delimiter);
void print_list_str(list_str *list);
int delete_node_at_index(list_str **head, int index);
int get_node_index(list_str *head, list_str *node);
list_str *add_node_end(list_str **head, const char *str, int num);


/* environ.c */
int my_setenv(passinf *);
int my_unsetenv(passinf *);
int populate_env_list(passinf *);
char *get_env(passinf *, const char *);
int my_env(passinf *);
char *starts_with(const char *str, const char *prefix);

/* errors.c */
void e_puts(char *);
int e_putchar(char);
int put_fd(char x, int fd);
int puts_fd(char *str, int fd);


/* errors_1.c */
int err_str(char *);
void print_errors(passinf *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/*exit.c*/
char *strn_cpy(char *, char *, int);
char *strn_cat(char *, char *, int);
char *str_chr(char *, char);

/* get_line.c */
ssize_t get_input(passinf *);
int get_line(passinf *, char **, size_t *);
void sigint_Handler(int);
ssize_t input_buf(passinf *inf, char **buf, size_t *lent);
ssize_t get_input(passinf *inf);
ssize_t read_buf(passinf *inf, char *buf, size_t *w);
int get_line(passinf *inf, char **ptr, size_t *length);
void sigint_Handler(int sig_numb);
void build_history_list(passinf *inf, char *buf, int hist_count);
void check_chain(passinf *inf, char *buf, size_t *z, size_t w, size_t lent);
int is_chain(passinf *inf, char *buf, size_t *z);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


/* get_info.c */
void clear_inf(passinf *);
void set_inf(passinf *, char **);
void free_inf(passinf *, int);

/* get_env.c */
char **get_environ(passinf *);
int unset_env(passinf *, char *);
int set_env(passinf *, char *, char *);
void replace_alias(passinf *inf);
void replace_vars(passinf *inf);
void ffree(char **arr);
void free_list(list_str **head);
void bfree(void **ptr);
char **list_to_strings(list_str *list);



#endif
