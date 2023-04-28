#include "main.h"

/**
 * main - test simple shell
 * @ac: int type number
 * @av: pointer to strings type
 * Return:0
 */


int main(int ac, char **av)
{
	int i = 0, j, token_num = 0;
	char *delim = " \n\t", *token; //*prompt = "cisfun$ " *token;
	char *command = NULL, *command_copy = NULL;
	char *user = getenv("USER");
	size_t n = 0;
	ssize_t charnum;
	char **tokens;
	user = strcat(user, "$ ");

	while (1)
	{
	write(STDOUT_FILENO, user, strlen(user));
	charnum = getline(&command, &n, stdin);

	if (charnum == -1 || charnum == EOF)
	{
		free(command);
		exit(0);
	}

	command[strcspn(command, "\n")] = '\0';
	command_copy = malloc(sizeof(char) * charnum);
	if (command_copy == NULL)
	{
		perror("shell: memory allocation error");
		return (-1);
	}
	strcpy(command_copy, command);

	/* ------------ PARSING ----------------------*/

	token = strtok(command, delim);

	while (token != NULL)
	{
		token_num++;
		token = strtok(NULL, delim);
	}
	token_num++;

	av = malloc(sizeof(char *) * token_num);
	token = strtok(command_copy, delim);

	for (i = 0 ; token != NULL ; i++)
	{
		av[i] = malloc(sizeof(char) * strlen(token));
		strcpy(av[i], token);
		token = strtok(NULL, delim);
	}
	av[i] = NULL;

	
	/* -------------PARSING ---------------------*/
	builtin_execute(av);
}
	free(command);
	return (0);
}

