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
	int (*builtin_func)(char **, char **, char **);

	if (tokens)
	{
		builtin_func = is_builtin(tokens[0]);
		if (builtin_func)
		{
			status = exec_builtin(builtin_func, tokens, env, argv);
			return (status);
		}

		pid = fork();

		if (pid == 0)
		{
			if (execve(tokens[0], tokens, env) == -1)
			{
				print_error(argv[0], NULL);
				perror(tokens[0]);
				exit(127);
			}
		}
		else if (pid < 0)
		{
			print_error(argv[0], NULL);
			perror(tokens[0]);
			exit(127);
		}
		else
		{
			do {
				waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
	return (status);
}
