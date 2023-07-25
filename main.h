#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>


/* parse.c */
int count_tokens(char *buffer, char *delim);
void handle_comments(char **tokens);
char **parse(char *buffer, char *delim);

/* search.c */
char *search(char *command);

/* exec.c */
int execute(char **tokens, char *argv[], char **env);

/* builtins.c */
int (*is_builtin(char *cmd))(char **, char **, char **);
int exec_builtin(int (*func)(char **, char **, char **), char **tokens, char **env, char **argv);
int handle_exit_args(char **tokens, char **argv);
int builtin_exit(__attribute__((unused)) char **tokens, __attribute__((unused)) char **env, __attribute__((unused)) char **argv);
int builtin_env(__attribute__((unused)) char **tokens, char **env, __attribute((unused)) char **argv);
int builtin_cd(char **tokens, __attribute__((unused)) char **env, char **argv);

/**
 * struct builtin_t - structure to hold
 * the builtin command and their functions
 * @cmd: pointer to string (command name)
 * @func: command function
 */
typedef struct builtin_t
{
	char *cmd;
	int (*func)(char **, char**, char **);
} builtin_s;

/* utils.c */

void print_error(char *program_name);
void free_dptr(char **dptr);
int _atoi(char *str);
int handle_program_return_value(char **tokens, char **argv, int status);


#endif


