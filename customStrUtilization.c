#include "shell.h"

/**
* customStrLength - returns the length of a string
* @str: string
* Return: string length
*/

int customStrLength(const char *str)
{
	int len = 0;

	if (s == NULL)
		return (0);
	do {
		len++;
	} while (str[len] != '\0');
	return (len);
}

/**
* customStrCopy - copies from source to destination
* @destination: where it copies to
* @source: where it copies from
* Return: destination pointer
*/

char *customStrCopy(char *destination, const char *source)
{
	int count = 0;

	do {
		destination[count] = source[count];
		count++;
	} while (source[count]);
	destination[count] = '\0';
	return (destination);
}

/**
* customStrDup - pointer to the new string which is a duplicate
* @input_str: string to be duplicated
* Return: pointer to the dupicated string
*/

char *customStrDup(const char *input_str)
{
	char duplicate;

	if (input_str == NULL)
	{
		return;
	}
	else
	{
		duplicate = malloc(sizeof(char) * (customStrLength(input_str) + 1));
		if (duplicate == NULL)
			return (NULL);
		return (customStrCopy(duplicate, input_str));
	}
}

/**
* customStringCat - concatenates two strings
* @destination: destination address
* @source: source
* Return: pointer to the destination string
*/

char *customStringCat(char *destination, const char *source)
{
	char *ptr = destination;
	int count = 0, counter = 0;

	if (source == NULL)
		return (ptr);
	while (destination[count] != '\0')
	{
		count++;
	}
	while (source[counter] != '\0')
	{
		destination[count] = source[counter];
		count++;
		counter++;
	}
	destination[count] = '\0';

	return (ptr);
}

/**
* customStrConcat - concatenates 2 strings ton a new mem aaddress
* @str1: string 1
* @str2: string 2
* Return: memory address of the string
*/

char *customStrConcat(const char *str1, const char *str2)
{
	char address;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	address = malloc(customStrLength(str1) + customStrLength(str2) + 1);
	if (!address)
	{
		perror("MALLOC");
		return (MULL);
	}
	customStrCopy(address, str1);
	customStrCat(address, str2);
	return (address);
}
