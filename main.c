#include "main.h"

/**
 * main - Entry point for shell
 * @ac: arguments counter
 * @av: arguments vector
 * @env: enviroment variables
 * Return: 0 if success
 */

int main(int ac __attribute__ ((unused)), char **av, char **env)
{
	int chars;
	size_t buff_size = 0;
	char *buffer = NULL;
	char prompt[4] = "$ ";
	char **tokens;

	char __attribute__((unused)) *tok;

	while (1)
	{

		if (isatty(0))
			write(1, prompt, 2);

		chars = my_getline(&buffer, &buff_size, stdin);

		/* handle EOF */
		if (chars < 0)
		{
			return (0);
		}

		tok = strtok(buffer, " \n");

		tokens = extract_args(buffer, " \n");

		execute(tokens, av, env);

	}

	return (0);
}

