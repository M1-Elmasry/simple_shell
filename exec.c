#include "main.h"

/**
 * f_ptr is_builtin - builtin functions
 * @cmd: commands written by user
 * Return: NULL
 */

f_ptr is_builtin(char *cmd)
{
	int i;
	builtin_funcs cmds[] = {
		{"help", &sh_help}, {"cd", &sh_cd},
		{"exit", &sh_exit}, {"env", &sh_env}
	};

	for (i = 0; i < 4; i++)
	{
		if (!_strcmp(cmd, cmds[i].command_name))
		{
			return (cmds[i].fun);
		}
	}
	return (NULL);
}

/**
 * search_cmd - command searching in path
 * @cmd: commands written by user
 * Return: cmd
 */

char *search_cmd(char *cmd)
{
	int i = 0;
	char *path, *s_paths;
	char *s_paths2, __attribute__ ((unused)) *tok;
	char **tokens;
	struct stat s;

	if (!cmd)
		return (0);

	s_paths = _getenv("PATH");
	s_paths2 = strdup(s_paths);
	tok = strtok(s_paths2, ":");
	tokens = extract_args(s_paths2, ":");

	while (tokens[i] != NULL)
	{
		path = calloc((_strlen(tokens[i]) + _strlen(cmd)) + 2, sizeof(char));

		if (!path)
		{
			perror("allocation failed");
			exit(EXIT_FAILURE);
		}

		_strcpy(path, tokens[i]);
		_strcat(path, "/");
		_strcat(path, cmd);

		if (stat(path, &s) == 0)
		{
			if ((s.st_mode & X_OK) > 0)
			{
				free(s_paths2);
				return (path);
			}
			++i;
		}
		++i;
	}
	return (cmd);
}


/**
 * execute - command execution
 * @args: arguments written by the user
 * @argv: arguments
 * @env: enviroment variables
 * Return: int
 */
int execute(char *args[], char **argv, char **env)
{
	pid_t pid;
	int status;
	char *cmd_path;
	f_ptr cmd_function;

	if (!args)
		exit(EXIT_FAILURE);

	if (**args == 10)
		return (0);

	cmd_function = is_builtin(args[0]);
	if (cmd_function)
		return (cmd_function(args, argv, env));
	cmd_path = search_cmd(args[0]);

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd_path, args, NULL) == -1)
		{
			perror(argv[0]);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror(argv[0]);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}
