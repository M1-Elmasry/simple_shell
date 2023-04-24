#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>


/* X for owner or group or user */
#define EXEC 0b1001001 

typedef int (*f_ptr)(char **);

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
char **extract_args(char *tok, char *delim);
int execute(char *args[], char **argv, char **env);
char *search_cmd(char *cmd);
int args_len(char **args);
int sh_cd(char **args);
int sh_help(char **args);
int sh_exit(char **args);
int sh_env(char **args);

typedef struct builtins
{
	char *command_name;
	f_ptr fun;

} builtin_funcs;

#endif
