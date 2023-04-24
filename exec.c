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
		if (!strcmp(cmd, cmds[i].command_name))
		{
			return (cmds[i].fun);
		}
	}
	return (NULL);
}

char *search_cmd(char *cmd)
{
	int i = 0;
	char *path, *s_paths, *s_paths2, *tok;
	char **tokens;
	struct stat s;

	if (!cmd)
		return (0);

	s_paths = getenv("PATH");
	s_paths2 = strdup(s_paths);
	tok = strtok(s_paths2, ":");
	tokens = extract_args(s_paths2, ":");

	while (tokens[i] != NULL)
	{
		path = calloc((strlen(tokens[i]) + strlen(cmd)) + 2, sizeof(char));

		if (!path)
		{
			perror("allocation failed");
			exit(EXIT_FAILURE);
		}

		strcpy(path, tokens[i]);
		strcat(path, "/");
		strcat(path, cmd);

		if (stat(path, &s) == 0)
		{
			if ((s.st_mode & EXEC) > 0)
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


int execute(char *args[], char **argv, char **env)
{
	pid_t pid;
	int status;
	char *cmd_path;
	f_ptr cmd;

	if (!args)
		exit(EXIT_FAILURE);

	if (**args == 10)
		return (0);

	cmd = is_builtin(args[0]);
	if (cmd)
		return (cmd(args));
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
