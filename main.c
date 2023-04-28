#include "main.h"

/**
 * main - Entry point for shell
 * @ac: arguments counter
 * @av: arguments vector
 * @env: enviroment variables
 * Return: 0 if success
 */

int main(int ac, char **av, char **env)
{
	int chars;
	size_t buff_size = 0;
	char *buffer = NULL;
	char prompt[2] = "$ ";
	char **tokens;

	char __attribute__((unused)) *tok;

	(void)ac;

	while (1)
	{

		if (isatty(0))
			write(1, prompt, 2);

		chars = getline(&buffer, &buff_size, stdin);

		/* handle EOF */
		if (chars < 0)
		{
			free(buffer);
			return (0);
		}

		tok = strtok(buffer, " \n");

		tokens = extract_args(buffer, " \n");

		execute(tokens, av, env);

		free(tokens);
	}
	free(tokens);
	free(buffer);
	return (0);
}
