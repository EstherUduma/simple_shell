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
* @size: number of characters to copy
* Return: The number of characters copied
*/

int customStringCopy(char *destination, const char *source, int size)
{
	int i;

	for (i = 0; i < size && source[i] != '\0'; i++)
	{
		destination[i] = source[i];
	}
	destination[i] =  '\0';

	return (i);
}
