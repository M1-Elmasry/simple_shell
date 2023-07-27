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

/**
 * exec_builtin - prototype to exec_builtin functon
 * @func: pointer to the builtin function that will execute
 * @tokens: elements of the entered command line
 * @env: environment variables
 * @argv: program arguments
 * Return: status of executing
 */
int exec_builtin(int (*func)(char **, char **, char **),
		char **tokens, char **env, char **argv);
int handle_exit_args(char **tokens, char **argv);

/**
 * builtin_exit - prototype to builtin_exit function
 * @tokens: the cmmmand line that is entered by user
 * @env: enviroment variables
 * @argv: prgram arguments
 * Return: -1
 */
int builtin_exit(__attribute__((unused)) char **tokens,
		__attribute__((unused)) char **env,
		__attribute__((unused)) char **argv);

/**
 * builtin_env - prototype to builtin_env function
 * @tokens: the cmmmand line that is entered by user
 * @env: enviroment variables
 * @argv: prgram arguments
 * Return: 0
 */
int builtin_env(__attribute__((unused)) char **tokens,
		char **env,
		__attribute((unused)) char **argv);
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

void print_error(char *program_name, char *msg);
void free_dptr(char **dptr);
int _atoi(char *str);
int handle_program_return_value(char **tokens, char **argv, int status);


#endif


