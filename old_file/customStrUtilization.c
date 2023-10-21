#include "shell.h"

/**
* customStringCompare - this compares two strings
* @strA: the first string to be compared
* @strB: the second string to be compated
* Return: 0 if equal or otherwise if not
*/

int customStringCompare(const char *strA, const char *strB)
{
	while (*strA && (*strA == *strB))
	{
		strA++;
		strB++;
	}

	return (*(unsigned char *)strA - *(unsigned char *)strB);
}

/**
* customStringLength - the length of the string
* @str: the input string
* Return: the length of the string
*/

int customStringLength(const char *str)
{
	int length = 0;

	while (str[length])
	{
		length++;
	}

	return (length);
}

/**
* customStringCopy - copies a specified number of characters
* to a destination
* @destination: the destination sting
* @source: the source string
* Return: The number of characters copied
*/

int customStringCopy(char *destination, const char *source)
{
	int count;

	for (count = 0; source[count] != '\0'; count++)
	{
		destination[count] = source[count];
	}
	destination[count] =  '\0';

	return (count);
}

/**
* custom_strncmp - this compares 2 strings up to a specified size
* @s1: string 1
* @s2: string 2
* @n: size
* Return: 0 if equal, +ve if s1 is > and -ve if s2 is >
*/

int custom_strncmp(const char *s1, const char *s2, size_t  n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if ((s1[i] != s2[i]) || s1[i] == '\0' || s2[i] == '\0')
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}
