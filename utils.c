#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

char **extract_args(char *tok)
{
	int i, n_args = 0;
	char **args = NULL;

	if (!tok)
	{
		return (0);
	}

	while (tok == NULL)
	{
		n_args++;
		tok = strtok(NULL, " \n");
	}

	args = calloc(n_args + 1, sizeof(char*));

	if (!args)
	{
		return (0);
	}

	for (i = 0; tok != NULL; i++)
	{
		args[i] = calloc(strlen(tok), sizeof(char));

		if (!args[i])
		{
			return (0);
		}

		strcpy(args[i], tok);

		tok = strtok(NULL, " \n");
	}

	return (args);
}


void execute(char *args[], char *filename)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0) 
	{

		if (execve(args[0], args, NULL) == -1) 
		{
			perror(filename);
		}
		exit(EXIT_FAILURE);
	}

	else if (pid < 0) 
	{
		perror(filename);
	}

	else
	{
		do 
		{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
