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

char **extract_args(char *tok, char *delim);
int execute(char *cmd, char *args[], char *filename);
char *search_cmd(char *cmd);
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
