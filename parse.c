#include "main.h"

/**
 * count_tokens - counts the number of elements in buffer
 * @buffer: command entered by the user
 * @delim: delimintion character for tokinization
 * Return: number of tokens
 */
int count_tokens(char *buffer, char *delim)
{
	int num = 0;
	char *token = NULL, *buffer_copy = NULL;

	buffer_copy = strdup(buffer);
	token = strtok(buffer_copy, delim);

	while (token != NULL)
	{
		num++;
		token = strtok(NULL, delim);
	}
	num++;

	free(buffer_copy);
	return (num);
}


/**
 * parse - parse the buffer to tokens
 * @buffer: buffer
 * @delim: delimeter
 * Return: tokens
 */
char **parse(char *buffer, char *delim)
{
	int i = 0;
	int tokens_num = count_tokens(buffer, delim);
	char *token, **tokens, *buffer_copy;

	if (!buffer)
		return (NULL);

	tokens = malloc(sizeof(char *) * (tokens_num));
	if (tokens == NULL)
		return (NULL);

	buffer_copy = strdup(buffer);

	token = strtok(buffer_copy, delim);

	while (token != NULL)
	{
		/* stop append tokens when see # (after space) */
		if (token[0] == '#')
			break;

		tokens[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;

	free(buffer_copy);
	return (tokens);
}
