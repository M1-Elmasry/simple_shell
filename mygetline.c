#include "main.h"

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t buffer_size = 0;
	ssize_t bytes_read = 0;
	char *buffer = NULL;
	int c;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	buffer = *lineptr;
	buffer_size = *n;

	while ((c = getc(stream)) != EOF)
	{
		if (bytes_read + 1 > buffer_size)
		{
			size_t new_size = buffer_size * 2;

			if (new_size < bytes_read + 1)
				new_size = bytes_read + 1;
			char *new_buffer = realloc(buffer, new_size);

			if (new_buffer == NULL)
				return (-1);
			buffer = new_buffer;
			buffer_size = new_size;
			*lineptr = buffer;
			*n = buffer_size;
		}
		buffer[bytes_read++] = c;
		if (c == '\n')
			break;
	}
	if (bytes_read == 0)
		return (-1);
	buffer[bytes_read] = '\0';
	return (bytes_read);
}

