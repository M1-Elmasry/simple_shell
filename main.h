#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

char **extract_args(char *tok);
void execute(char *args[], char *filename);
int sh_cd(char **args);
int sh_help(char **args);
int sh_exit(char **args);
int sh_env(char **args);

typedef struct builtins
{
	char *command_name;
	int (*fun)(char **);

} builtin_funcs;

#endif
