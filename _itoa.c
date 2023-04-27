#include "main.h"

/**
 * _itoa - simple impelementation to itoa function
 * this function convert the int number to string number
 * @n: integer number
 * Return: pointer to the number after converted to string
 */
char *_itoa(int n)
{
	/**
	 * Maximum length of a signed 32-bit integer
	 * is 11 digits plus a null terminator
	 */
	char *s = malloc(12), c;
	int i = 0, sign = n, j;

	if (sign < 0)
		n = -n;

	do {
		s[i++] = n % 10 + '0';
	} while (n /= 10);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';

	for (j = 0; j < i / 2; j++)
	{
		c = s[j];
		s[j] = s[i - j - 1];
		s[i - j - 1] = c;
	}
	return (s);
}
