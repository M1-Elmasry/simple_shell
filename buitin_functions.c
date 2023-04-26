#include "main.h"

/**
 * sh_cd - cd builtin command
 * @args: cd with it arguments
 * @argv: program arguments
 * @env: enviroment variables
 * Return: 0 if success
 */

int sh_cd(char **args,
		char **argv,
		char **env __attribute__((unused)))
{
	char *home = _getenv("HOME");

	if (!args)
		return (0);

	if (args_len(args) > 2)
	{
		write(2, argv[0], _strlen(argv[0]));
		write(2, ": cd: too many arguments\n", 25);
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
			write(2, ": cd: ", 6);
			perror(args[1]);
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

int sh_help(char **args __attribute__((unused)),
		char **argv __attribute__((unused)),
		char **env __attribute__((unused)))
{
	printf("hello from my shell\n");
	return (0);
}

/**
 * sh_exit - exit builtin command
 * @args: exit with it arguments
 * @argv: program arguments
 * @env: enviroment variables
 * Return: 0 if success
 */

int sh_exit(char **args __attribute__((unused)),
		char **argv __attribute__((unused)),
		char **env __attribute__((unused)))
{
	if (!args)
		return (0);

	printf("exit\n");
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
int sh_env(char **args __attribute__((unused)),
		char **argv __attribute__((unused)),
		char **env)
{
	int i = 0;

	if (!args)
		return (0);

	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}

