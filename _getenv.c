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
		swap = malloc((_strlen(var_name) + 1) * sizeof(char));

		if (!swap)
		{
			free(swap);
			return (NULL);
		}

		_strncpy(swap, environ[i], _strlen(var_name));
		swap[_strlen(var_name)] = '\0';

		k = _strcmp(var_name, swap);
		if (k == 0)
		{
			free(swap);
			return (*(environ + i) + (_strlen(var_name) + 1));
		}
		free(swap);
	}
	return (NULL);
}
