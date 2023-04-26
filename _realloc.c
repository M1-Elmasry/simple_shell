#include "main.h"

/**
 * _realloc_s - reallocate block of memory to char data type only
 * @ptr: pointer
 * @new_size: new_size of @ptr
 * Return: pointer after reallocating
 */
char *_realloc_s(char *ptr, unsigned int new_size)
{
	int i = 0;
	char *temp_ptr;

	if (!ptr)
		return (malloc(new_size));

	temp_ptr = ptr;
	ptr = malloc(new_size);

	while (temp_ptr[i])
	{
		ptr[i] = temp_ptr[i];
	}

	return (ptr);
}
