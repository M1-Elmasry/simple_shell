#include "main.h"

/**
 * token_counter - Afunction that counts the number of arguments
 * @command: command entered by the user
 * @delim: delimintion character for tokinization
 */

int token_counter(char *command, char *delim)
{
	int num = 0;
	char *token = NULL;

	token = strtok(command, delim);

	while (token != NULL)
	{
		num++;
		token = strtok(NULL, delim);
	}
	num++;
	return (num);
}
