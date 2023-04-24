#include "main.h"

/**
 * extract_args - argument extraction by tokenization
 * @tok: tokens
 * @delim: deliminations
 * Return: pointer to chars
 */
char **extract_args(char *tok, char *delim)
{
	int buffer_size = 8, i = 0;
	char **args = malloc((buffer_size + 1) * sizeof(char *));

	if (!args)
	{
		perror("allocation failed");
		exit(EXIT_FAILURE);
	}

	while (tok != NULL)
	{
		if (i >= buffer_size)
		{
			buffer_size *= 2;
			args = realloc(args, (buffer_size + 1) * sizeof(char *));
			if (!args)
			{
				perror("allocation failed 1");
				exit(EXIT_FAILURE);
			}
		}
		args[i] = tok;
		++i;

		tok = strtok(NULL, delim);
	}

	args[i] = NULL;

	return (args);
}

int args_len(char **args)
{
	int i = 0;

	while (args[i])
	{
		i++;
	}

	return (i);
}


