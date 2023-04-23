#include "main.h"

/*
 *
 */

int main(int ac, char **av , char **env)
{
	int chars;
	size_t buff_size = 0;
	char *buffer = NULL;
	char *prompt = "=>> ";
	char *tok;
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

		execute(tokens, av, env);

	}

	return (0);
}

