#include "main.h"

/**
 * _strlen - function to get length of string
 * @s: pointer to string
 * Return: number of chars in @s
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (s[i])
	{
		i++;
	}
	return (i);
}


/**
 * *_strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer string
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int len = 0, i;

	if (!dest)
		return (0);

	if (!src)
		return (dest);

	while (src[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}

	dest[len] = '\0';

	return (dest);
}


/**
 * _strcat - concatenate two strings
 * @dest: first string
 * @src: second string
 * Return: @src concatenated with @dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, dest_len = 0;

	if (!dest)
		return (0);

	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}

	while (1)
	{
		if (src[i] != '\0')
		{
			dest[dest_len + i] = src[i];
		}
		else
		{
			break;
		}
		i++;
	}
	return (dest);
}

/**
 * _strncpy - copy string
 * @dest: pointer to string
 * @src: pointer to string
 * @n: something
 * Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int len1 = 0;
	int len2 = 0;
	int i;

	while (src[len1] != '\0')
		len1++;

	while (dest[len2] != '\0')
		len2++;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp - compare each string char string
 * @s1: first string
 * @s2: second string
 * Return: 0 if @s1 == @s2
 * positive integer if @s1 > @s2
 * negaitve integer if @s1 < @s2
 */
int _strcmp(char *s1, char *s2)
{
	int i, output = 0;

	for (i = 0; (*(s1 + i) != '\0') && (*(s2 + i) != '\0'); i++)
	{
		output += (*(s1 + i)) - (*(s2 + i));
		if (output != 0)
		{
			break;
		}
	}
	return (output);
}
