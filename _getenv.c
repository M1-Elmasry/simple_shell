#include "main.h"

/**
 * _getenv - get the value of enviroment variable
 * @var_name: variable name
 * Return: pointer to the value of @var_name
 * or NULL if no match
 */
char *_getenv(char *var_name)
{
	int i, k;
	char *swap;

	for (i = 0; environ[i] != NULL; i++)
	{
		swap = malloc(_strlen(var_name) * sizeof(char));

		_strncpy(swap, environ[i], _strlen(var_name));
		k = _strcmp(var_name, swap);
		if (k == 0)
		{
			return (*(environ + i) + (_strlen(var_name) + 1));
		}
	}
	return (NULL);
}
