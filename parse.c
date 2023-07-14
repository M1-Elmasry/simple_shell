#include "main.h"

/**
 * count_tokens - Afunction that counts the number of arguments
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

	free(token);
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
	char *token, **tokens;

	tokens = malloc(sizeof(char *) * (tokens_num));
	if (tokens == NULL)
		return (NULL);

	token = strtok(buffer, delim);

	while (token != NULL)
	{
		tokens[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;

	return (tokens);

}



















