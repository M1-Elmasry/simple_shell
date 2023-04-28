#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

//char **parsing (char *command, char *command_copy, char *delim, char **av)
int builtin_execute(char **av);
int executing(char **av);
char *path_location(char *command);
int shell_cd(char **av);
int shell_help(char **av);
int shell_exit(char **av);
int token_counter(char *command, char *delim);
char **parsing(char *command_copy, char *delim, int token_num);

#endif
