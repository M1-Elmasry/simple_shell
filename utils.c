#include "main.h"

char **extract_args(char *tok)
{
	int buffer_size = 8, i = 0;
	char **args = malloc((buffer_size + 1) * sizeof(char*));

	if (!args)
	{
		perror("allocation failed");
		exit(EXIT_FAILURE);
	}

	while (tok != NULL)
	{
		if (i >= buffer_size)
		{
			buffer_size *= 2;
			args = realloc(args, (buffer_size + 1) * sizeof(char*));
			if (!args)
			{
				perror("allocation failed 1");
				exit(EXIT_FAILURE);
			}
		}
			args[i] = tok;
			++i;

			tok = strtok(NULL, " \n");
	}

	args[i] = NULL;

	return (args);
}

void execute(char *args[], char *filename)
{
	pid_t pid;
	int status;

	if (!args)
		exit(EXIT_FAILURE);

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
