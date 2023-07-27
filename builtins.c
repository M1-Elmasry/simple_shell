#include "main.h"

/**
 * is_builtin - check if entered command is builtin
 * @cmd: first element in entered commnad line
 * Return: builtin command function if is or -1 if isn't
 */
int (*is_builtin(char *cmd))(char **, char **, char **)
{
	int i;
	builtin_s cmds[] = {{"exit", builtin_exit},
		{"env", builtin_env},
		{"cd", builtin_cd}};

	for (i = 0; i < 3; i++)
	{
		if (strcmp(cmd, cmds[i].cmd) == 0)
			return (cmds[i].func);
	}
	return (NULL);
}


/**
 * exec_builtin - execute builtin commands
 * @func: pointer to the builtin function that will execute
 * @tokens: elements of the entered command line
 * @env: environment variables
 * @argv: program arguments
 * Return: status of executing
 */
int exec_builtin(int (*func)(char **, char **, char **),
		char **tokens, char **env, char **argv)
{
	int status;

	status = func(tokens, env, argv);

	return (status);
}

/**
 * builtin_exit - impelementation of exit command
 * @tokens: the cmmmand line that is entered by user
 * @env: enviroment variables
 * @argv: prgram arguments
 * Return: -1
 */
int builtin_exit(__attribute__((unused)) char **tokens,
		__attribute__((unused)) char **env,
		__attribute__((unused)) char **argv)
{
	return (-1);
}

/**
 * handle_exit_args - handling the exit command arguments
 * @tokens: the cmmmand line that is entered by user
 * @argv: program arguments
 * Return: 1 if more than 2 commands entered
 * or 2 if string entered instead of status code
 * or status code
 *
 * Description: we handle the the arguments of exit command
 * individually to avoid the conflict between
 * waitpid status and exit status
 */
int handle_exit_args(char **tokens, char **argv)
{
	int n;

	if (tokens[2]) /* if args > 2 */
	{
		print_error(argv[0], NULL);
		write(STDERR_FILENO, "exit: too many arguments\n", 25);
		return (1); /* will exit with this status */
	}

	n = _atoi(tokens[1]);
	if (n == -1)
	{
		print_error(argv[0], NULL);
		write(STDERR_FILENO, "exit: ", 6);
		write(STDERR_FILENO, tokens[1], strlen(tokens[1]));
		write(STDERR_FILENO, ": numeric argument required\n", 28);
		return (2); /* will exit with this status */
	}
	/* if nothing happend will exit with status code between 0 and 255 */
	return (n % 256);
}

/**
 * builtin_env - impelementation of env command
 * @tokens: the cmmmand line that is entered by user
 * @env: enviroment variables
 * @argv: program arguments
 * Return: 0
 */
int builtin_env(__attribute__((unused)) char **tokens, char **env,
		__attribute__((unused)) char **argv)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
		write(STDOUT_FILENO, env[i], strlen(env[i]));

	return (0);
}

/**
 * builtin_cd - impelementation of cd command
 * @tokens: the cmmmand line that is entered by user
 * @env: enviroment variables
 * @argv: program arguments
 * Return: 0
 */
int builtin_cd(char **tokens, __attribute((unused)) char **env, char **argv)
{
	char *cwd = NULL, *HOME, *OLDPWD;

	cwd = getcwd(cwd, 512);
	HOME = getenv("HOME");
	if (!tokens[1])
	{
		setenv("OLDPWD", cwd, 1);
		chdir(HOME);
	}
	else if (strcmp(tokens[1], "-") == 0)
	{
		OLDPWD = getenv("OLDPWD");
		if (OLDPWD == NULL)
			print_error(argv[0], "cd: OLDPWD not set\n");
		else
		{
			setenv("OLDPWD", getcwd(cwd, 512), 1);
			chdir(OLDPWD);
		}
	}
	else if (!tokens[2])
	{
		OLDPWD = getcwd(cwd, 512);
		if (chdir(tokens[1]) == 0)
			setenv("OLDPWD", OLDPWD, 1);
		else
		{
			print_error(argv[0], "cd: ");
			perror(tokens[1]);
		}
	}
	else
		print_error(argv[0], "cd: too many arguments\n");
	free(cwd);
	return (0);
}
