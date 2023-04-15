#include "main.h"


int main(int ac, char **av, char **env)
{
	int chars, i;
	size_t buff_size = 0;
	char *prompt = "=>> ";
	char *buffer = NULL;
	char *tok;
	char **tokens;
	builtin_funcs cmds[] = {
		{"help", &sh_help}, {"cd", &sh_cd},
		{"exit", &sh_exit},{"env", &sh_env}
	};

	while (1)
	{
		printf("%s", prompt);
		chars = getline(&buffer, &buff_size, stdin);

		/* handle EOF */
		if (chars < 0)
		{
			return (0);
		}

		tok = strtok(buffer , " \n");

		tokens = extract_args(tok);

		/* executing the builtin commands */
/*		for (i = 0; i < sizeof(cmds) / sizeof(cmds[0]); i++)
		{
			if (tokens[0] == cmds[i][0])
			{
				cmds[i][1](tokens);
			}
		}
*/
		execute(tokens, av[0]);
	}
	return 0;
}

