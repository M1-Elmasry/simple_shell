#include "main.h"

/**
 * print_error - prints entire error messanges
 * @program_name: name of this shell (argv[0])
 * Return: void
 */
void print_error(char *program_name)
{
	write(STDERR_FILENO, program_name, strlen(program_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "line 1: ", 8);

}

/**
 * free_dptr - free double pointer
 * @dptr: double pointer
 * Return: void
 */
void free_dptr(char **dptr)
{
	int i;

	for (i = 0; dptr[i] != NULL; i++)
	{
		free(dptr[i]);
	}
	free(dptr);
}

/**
 * _atoi - convert string number to int
 * @str: pointer to string number
 * Return: int number or -1 if failure
 */
int _atoi(char *str)
{
	int result = 0, sign = 1, digit;

	if (*str == '-')
	{
		sign = -1;
		++str;
	}

	while (*str != '\0')
	{
		digit = *str - '0';

		if (digit >= 0 && digit <= 9)
			result = result * 10 + digit;
		else /* Invalid character found */
			return (-1);
		++str;
	}

	result *= sign;
	return (result);
}


/**
 * handle_program_return_value - this function handle the status that
 * shell should return according to status value
 * @tokens: the command line entered by user
 * @argv: program arguments
 * @status: status of executing proccess
 * Return: 0 if nothing happend while executing else exit with specific code
 */
int handle_program_return_value(char **tokens, char **argv, int status)
{
	int exit_code = 0;

	if (status > 0) /* an error eccur while executing */
	{
		if (status == 1) /* executing failed */
			exit(1);

		if (status == 512) /* execute function throw cannot access error */
			exit(2);

		exit(127);
	}
	else if (status == -1) /* exit called */
	{
		if (tokens[1]) /* check if exit enterd with code */
			exit_code = handle_exit_args(tokens, argv);
		free_dptr(tokens);
		exit(exit_code);
	}
	else
		return (0);
}
