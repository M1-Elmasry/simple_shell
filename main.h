#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* used in _getenv */
extern char **environ;




/* used to put all builtin cmds functions in array without executing it */
typedef int (*f_ptr)(char **, char **, char **);


/**
 * struct builtins - contain data of builtin commands
 * @command_name: commmand_name
 * @fun: pointer to specific builin command function
 */
typedef struct builtins
{
	char *command_name;
	f_ptr fun;

} builtin_funcs;

/* reimpelemntation to builtin strings functions */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, const char *src, size_t n);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);


/* reimpelemention to builtin functions */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
char *_realloc_s(char *ptr, unsigned int new_size);
char *_getenv(char *var_name);
char *_itoa(int n);

/* utils functions */
char **extract_args(char *tok, char *delim);
int args_len(char **args);
void siginthandler(int n);
void sigtstphandler(int n);

/* builtin commands functions */
int sh_cd(char **args, char **argv, char **env);
int sh_help(char **args, char **argv, char **env);
int sh_exit(char **args, char **argv, char **env);
int sh_env(char **args, char **argv, char **env);


/* exucute functions */
f_ptr is_builtin(char *cmd);
char *search_cmd(char *cmd);
int execute(char *args[], char **argv, char **env);

#endif
