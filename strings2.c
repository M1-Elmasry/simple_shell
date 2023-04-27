#include "main.h"

/**
 * _strdup - simple impelentation to strdup
 * this function return duplicated string with allocated memory
 * @str: pointer to the string
 *
 * Return: pointer of the new allocated memory otherwise NULL
 */
char *_strdup(char *str)
{
	char *ptr;
	size_t size;

	if (!str)
		return (0);

	size = _strlen(str);
	ptr = malloc(size + 1);

	if (!ptr)
		return (0);

	ptr = _strcpy(ptr, str);

	return (ptr);
}
