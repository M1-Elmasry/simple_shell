#include "main.h"

/**
 * search - search for the command in path
 * @command: command entered by user
 * Return: founded executable path or NULL
 */
char *search(char *command)
{
	int i, j;
	char *PATH = NULL;
	char **PATH_tokens = NULL;
	char *test_path = NULL;
	struct stat buffer;

	PATH = getenv("PATH");

	if (!PATH)
		return (command);

	PATH_tokens = parse(PATH, ":");

	for (i = 0; PATH_tokens[i] != NULL; i++)
	{
		test_path = calloc(1, strlen(PATH_tokens[i]) + strlen(command) + 2);
		strcat(test_path, PATH_tokens[i]);
		strcat(test_path, "/");
		strcat(test_path, command);
		if (stat(test_path, &buffer) == 0)
		{
			for (j = 0; PATH_tokens[j] != NULL; j++)
				free(PATH_tokens[j]);
			free(PATH_tokens);
			return (test_path);
		}
	}
	free(test_path);
	return (command);
}
