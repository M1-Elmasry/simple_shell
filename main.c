#include "main.h"


int main(int ac __attribute__((unused)), char **av __attribute__((unused)), char **env __attribute__((unused)))
{
	int chars;
	size_t buff_size = 0;
	char *buffer = NULL;
	char *prompt = "=>> ";
	char *tok, *path;
	char **tokens;

	while (1)
	{
		printf("%s", prompt);
		chars = getline(&buffer, &buff_size, stdin);

		/* handle EOF */
		if (chars < 0)
		{
			return (0);
		}

		tok = strtok(buffer , " \n");
		tokens = extract_args(buffer, " \n");

		path = search_cmd(tokens[0]);
		execute(path, tokens, av[0]);

	}

	return (0);
}

