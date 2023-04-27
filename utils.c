#include "main.h"

/**
 * extract_args - argument extraction by tokenization
 * @tok: tokens
 * @delim: deliminations
 * Return: pointer to chars
 */

char **extract_args(char *tok, char *delim)
{
	int buffer_s = 8, i = 0;
	char **args = malloc((buffer_s + 1) * sizeof(char *));

	if (!args)
	{
		perror("allocation failed");
		exit(EXIT_FAILURE);
	}

	while (tok != NULL)
	{
		if (i >= buffer_s)
		{
			buffer_s *= 2;
			args = (char **)_realloc_s((char *)args, (buffer_s + 1) * sizeof(char *));
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

/**
 * args_len - lenght of argumants
 * @args: arguments
 * Return: int
 */
int args_len(char **args)
{
	int i = 0;

	while (args[i])
	{
		i++;
	}

	return (i);
}

/**
 * siginthandler - handle SIGINT signal (ctrl c)
 * @n: unused instead of void param to pass from gcc and betty warnings
 * Description: function will do nothing when catch SIGTSTP
 */
void siginthandler(int n)
{
	char new_read[3] = "\n$ ";

	(void)n;
	write(1, new_read, 3);
}

/**
 * sigtstphandler - handle SIGTSTP signal (ctrl z)
 * @n: unused instead of void param to pass from gcc and betty warnings
 * Description: function will do nothing when catch SIGTSTP
 */
void sigtstphandler(int n)
{
	(void)n;
	/* do nothing */
}
