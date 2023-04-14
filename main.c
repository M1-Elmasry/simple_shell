#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


int main(int ac, char **av, char **env)
{
	int chars;
	size_t buff_size = 0;
	char *prompt = "=>> ";
	char *buffer = NULL;
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

		tokens = extract_args(tok);

		execute(tokens, av[0]);
	}
	return 0;
}

