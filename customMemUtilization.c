#include "string.h"

/**
* custom_memcpy - this copies memory
* @dst: pointer to the destination memory
* @src: pointer to the source memory
* @n: number of bytes to copy
* Return: dst
*/

void *custom_memcpy(void *dst, const void *src, size_t n)
{
	char *dest = dst;
	const char *source = src;
	size_t i;

	for (i = 0; i < n; i++)
	{
		dest[i] = source[i];
	}

	return (dst);
}

/**
* custom_realloc - this reallocates the memory
* @ptr: pointer to the old memory block
* @size: new size for the memory block
* Return: New memory location
*/

void *custom_realloc(void *ptr, size_t size)
{
	void *new_ptr = malloc(size);

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_ptr != NULL && ptr != NULL)
	{
		custom_memcpy(new_ptr, ptr, size);
		free(ptr);
	}

	return (new_ptr);
}
