#include "main.h"

/**
 * main - test simple shell
 * @ac: int type number
 * @av: pointer to strings type
 * Return:0
 */

int main(int ac, char **av)
{
	int i = 0, j, token_num = 0;
	char *delim = " \n\t", *token;
	char *command = NULL, *command_copy = NULL;
	size_t n = 0;
	ssize_t charnum;
	char **tokens;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		charnum = getline(&command, &n, stdin);

		if (charnum == -1 || charnum == EOF)
		{
			free(command);
			exit(0);
		}

		command[strcspn(command, "\n")] = '\0';
		command_copy = malloc(sizeof(char) * (charnum));
		if (command_copy == NULL)
		{
			perror("shell: memory allocation error");
			return (-1);
		}

		strcpy(command_copy, command);
		token_num = token_counter(command, delim);
		av = parsing(command_copy, delim, token_num);
		free(command_copy);
		builtin_execute(av);

		for (i = 0; av[i] != NULL; i++)
		{
			free(av[i]);
		}
		free(av);
	}
	free(av);
	return (0);
}

