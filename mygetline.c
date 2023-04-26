#include "main.h"

/**
 *my_getline - getline implementation function
 * @lineptr: pointer to string to store written line
 * @n: buffer size
 * @stream: stream of file the data read from
 * Return: Number of characters of line written
 */

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t size = 0, new_size;
	ssize_t read = 0;
	char *buffer = NULL;
	char *new_buffer;
	int c;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	signal(SIGTSTP, sigtstphandler);
	signal(SIGINT, siginthandler);

	buffer = *lineptr;
	size = *n;

	while ((c = getc(stream)) != EOF)
	{
		if (read + 1 > (ssize_t) size)
		{
			new_size = size * 2;

			if (((ssize_t) new_size) < read + 1)
				new_size = read + 1;
			new_buffer = realloc(buffer, new_size);

			if (new_buffer == NULL)
				return (-1);
			buffer = new_buffer;
			size = new_size;
			*lineptr = buffer;
			*n = size;
		}
		buffer[read++] = c;
		if (c == '\n')
			break;
	}
	if (read == 0)
		return (-1);
	buffer[read] = '\0';
	return (read);
}

