#include "main.h"

/**
 * execute - execute entered command
 * @tokens: commands with it's arguments
 * @argv: program arguments
 * @env: environment variables
 * Return: 1 if success
 */
int execute(char **tokens, char *argv[], char **env)
{
	pid_t pid;
	int status;

	if (tokens)
	{
		pid = fork();

		if (pid == 0)
		{
			if (execve(tokens[0], tokens, env) == -1)
			{
				write(STDERR_FILENO, argv[0], strlen(argv[0]));
				write(STDERR_FILENO, ": ", 2);
				write(STDERR_FILENO, "line 1: ", 8);
				perror(tokens[0]);
				exit(EXIT_FAILURE);
			}

		}

		else if (pid < 0)
		{
			write(STDERR_FILENO, argv[0], strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, "line 1: ", 8);
			perror(tokens[0]);
			exit(EXIT_FAILURE);
		}

		else
		{
			do {
				waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
		return (1);
	}

	return (0);
}
