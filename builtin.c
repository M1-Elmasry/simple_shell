#include "main.h"

/**
 * shell_cd - change directory
 * @av: arguments
 * Return: 1
 */

int shell_cd(char **av)
{
	if (av[1] == NULL)
		perror("Error: ");
	else
		if (chdir(av[1]) != 0)
			perror("Error: ");
	return (1);

}

/**
 * shell_help - help
 * @av: arguments
 * Return: int
 */

int shell_help(__attribute__((unused))char **av)
{
	char *builtin[] = {
		"cd",
		"help",
		"exit"
	};

	int n  = 3;
	int i = 0;

	for (i = 0 ; i < n ; i++)
		printf(" %s\n", builtin[i]);

	return (0);
}

/**
 * shell_exit - exit shell
 * @av: arguments
 * Return: exit
 */

int shell_exit(char **av)
{
	(void)av;
	exit(EXIT_SUCCESS);
}
