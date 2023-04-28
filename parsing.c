#include "main.h"

/**
 * parsing - function that parses the command line
 * @command: string containing the command line
 * @delim: string containing the delimiters
 * @token_num: integer containing the number of tokens
 *
 * Return: char double pointer containing the tokens
 */
char **parsing(char *command, char *delim, int token_num)
{
	int i = 0;
	char *token, **tokens;

	tokens = malloc(sizeof(char *) * (token_num + 1));
	if (tokens == NULL)
		return (NULL);

	token = strtok(command, delim);
	while (token != NULL)
	{
		if (i >= token_num)
			break;

		tokens[i] = strdup(token);
		if (tokens[i] == NULL)
		{
			perror("shell: memory allocation error");
			for (; i >= 0; i--)
				free(tokens[i]);
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;

	return (tokens);
}
