#include "main.h"

/**
 * builtin_execute - builtin functions
 * @av: argumants
 * Return: int
 */

int builtin_execute(char **av)
{
	int i;

	char *builtin[] = {
		"cd", "help", "exit"
	};


	int (*builtin_func[]) (char **) = {
		&shell_cd,
		&shell_help,
		&shell_exit
	};


	if (av[0] == NULL)
		return (1);

	for (i = 0 ; i < 3 ; i++)
	{
		if (strcmp(av[0], builtin[i]) == 0)
			return ((*builtin_func[i])(av));
	}

	return (executing(av));
}
