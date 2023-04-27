#include "main.h"

/**
 * sh_cd - cd builtin command
 * @args: cd with it arguments
 * @argv: program arguments
 * @env: enviroment variables
 * Return: 0 if success
 */

int sh_cd(char **args, char **argv, char **env)
{
	char *home = _getenv("HOME");

	(void)env;

	if (!args)
		return (0);

	if (args_len(args) > 2)
	{
		if (chdir(args[1]) == -1)
		{
			write(2, argv[0], _strlen(argv[0]));
			write(2, ": ", 2);
			write(2, _itoa(1), 1);
			write(2, ": cd: can't cd to ", 19);
			write(2, args[1], _strlen(args[1]));
			write(2, "\n", 1);
		}
	}
	else if (args_len(args) == 1)
	{
		if (chdir(home) == -1)
		{
			return (0);
		}
	}
	else if (args_len(args) == 2)
	{
		if (chdir(args[1]) == -1)
		{
			write(2, argv[0], _strlen(argv[0]));
			write(2, ": ", 2);
			write(2, _itoa(1), 1);
			write(2, ": cd: can't cd to ", 19);
			write(2, args[1], _strlen(args[1]));
			write(2, "\n", 1);
		}
	}
	return (0);
}

/**
 * sh_help - help builtin command
 * @args: help with it arguments
 * @argv: program arguments
 * @env: enviroment variables
 * Return: 0 if success
 */

int sh_help(char **args, char **argv, char **env)
{
	(void)args;
	(void)argv;
	(void)env;

	write(1, "i can't help you, come back later", 34);
	write(1, "\n", 1);
	return (0);
}

/**
 * sh_exit - exit builtin command
 * @args: exit with it arguments
 * @argv: program arguments
 * @env: enviroment variables
 * Return: 0 if success
 */

int sh_exit(char **args, char **argv, char **env)
{
	(void)args;
	(void)argv;
	(void)env;

	if (!args)
		return (0);

	exit(EXIT_SUCCESS);
	return (0);
}

/**
 * sh_env - env builtin command
 * @args: env with it arguments
 * @argv: program arguments
 * @env: enviroment variables
 * Return: 0 if success
 */
int sh_env(char **args, char **argv, char **env)
{
	int i = 0;

	(void)args;
	(void)argv;

	if (!args)
		return (0);

	while (env[i])
	{
		write(1, env[i], _strlen(env[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

