#include "main.h"

/**
 * main - main function
 * @argc: program arguments count
 * @argv: pointer to program arguments
 * @envp: environment variables
 * Return: 0 if success
 */
int main(__attribute__((unused)) int argc, char *argv[], char *envp[])
{
	int readed_chars;
	char *buffer = NULL;
	char **tokens = NULL;
	char prompt[2] = "$ ";
	size_t buff_size = 0; /* getline will edit this with the right size */

	while (1)
	{
		/*print prompt */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, &prompt, 2);

		/* get input from the user */
		readed_chars = getline(&buffer, &buff_size, stdin);
		if (readed_chars == -1 || readed_chars == EOF)
		{
			break;
		}
		tokens = parse(buffer, " \n");
		execute(tokens, argv, envp);
	}

	free(buffer);
	free(tokens);
	return (0);
}
