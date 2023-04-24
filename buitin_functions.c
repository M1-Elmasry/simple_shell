#include "main.h"

/**
 * sh_cd - change directory
 * @args: arguments
 * Return: int
 */

int sh_cd(char **args)
{
	printf("cd done\n");
	return (0);
}

/**
 * sh_help - help in commands
 * @args: arguments
 * Return: int
 */

int sh_help(char **args)
{
	printf("hello from my shell\n");
	return (0);
}

/**
 * sh_exit - exit terminal
 * @args: arguments
 * Return: int
 */

int sh_exit(char **args)
{
	printf("exit done\n");
	return (0);
}

/**
 * sh_env - enviroment variables
 * @args: arguments
 * Return: int
 */
int sh_env(char **args)
{
	printf("env done\n");
	return (0);
}

