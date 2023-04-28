#include "main.h"

/**
 * executing - command execution in the shell
 * @av: arguments
 * Return: 1
 */

int executing(char **av)
{
	pid_t pid;
	int status;
	char *command = NULL, *real_command = NULL;

	if (av)
	{
		command = av[0];
		real_command = path_location(command);

		pid = fork();

		if (pid == 0)
		{

			if (execve(real_command, av, NULL) == -1)
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}

		}

		else if (pid < 0)
			perror("Error: ");

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
