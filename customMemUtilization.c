#include "shell.h"
#include <stdlib.h>

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

/**
* custom_strdup - this duplicates a string
* @input_str: this is the input string to duplicate
* Return: the new string
*/

char *custom_strdup(const char *input_str)
{
	char *new_str;

	if (input_str == NULL)
	{
		return (NULL);
	}

	new_str = malloc(customStringLength(input_str) + 1);

	if (new_str != NULL)
	{
		customStringCopy(new_str, input_str);
	}

	return (new_str);
}

/**
* custom_strcat - this concatenates two strings
* @destination: the destination string to append to
* @source: the source string to append to the destination
* Return: a pointer ti the concatenated string
*/

char *custom_strcat(char *destination, const char *source)
{
	char *p = destination + customStringLength(destination);

	if (destination == NULL || source == NULL)
		return (destination);

	while (*source != '\0')
	{
		*p++ = *source++;
	}
	*p = '\0';

	return (destination);
}

/**
* customFindChar - this finds a character in a string
* @source: the string to search
* @target: the character to find
* Return: pointer to the character's position or NULL
*/

char *customFindChar(const char *source, int target)
{
	char *result = (char *)source;

	while (*result != '\0')
	{
		if (*result == target)
		{
			return (result);
		}
		result++;
	}
	return (NULL);
}
