#include "EstherAnnUduma.h"

/**
* removeComments - removes comments from a buffer
* @buffer: buffer to be cleaned
* Return: pointer to the new buffer without comments
*/

char *removeComments(char *buffer)
{
	char *cleanBuffer = malloc(sizeof(char) * (customStrLength(buffer) + 1));
	int i;

	if (!cleanBuffer)
	{
		perror("MALLOC");
		return (NULL);
	}
	for (i = 0; buffer[i] && buffer[i] != '#'; i++)
		cleanBuffer[i] = buffer[i];
	cleanBuffer[i] = '\0';

	return (cleanBuffer);
}

/**
* isNotEmpty - checks if  buffer contains any non-space character
* @inputBuffer: command line to be executed
* Return: 0 if there are spaces and -1 if not
*/

int isNotEmpty(char *inputBuffer)
{
	int i;

	for (i = 0; inputBuffer[i] && inputBuffer[i] == ' '; i++)
	{
	}
	return ((inputBuffer[i] && inputBuffer[i] != '\n') ? -1 : 0);
}

/**
* areEqualStrings - compares two strings
* @str1: string1
* @str2: string2
* Return: 0 if str1 == str2, -1 if str1 != str2
*/

int areEqualStrings(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] && str2[i] && str1[i] == str2[i]; i++)
	{
	}
	return ((str1[i] == str2[i]) ? 0 : -1);
}

/**
* countCharOccurrences - count the number of times c appears
* @buffer: buffer to check
* @c: character to count
* Return: the count of c occurences + 1
*/

int countCharOccurrences(char *buffer, char c)
{
	int counter = 0, i;

	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] == c)
			counter++;
	}
	return (counter + 1);
}

/**
* replaceChar - replace all occurences of old char
* @buffer: input buffer
* @oldChar: character to be replaced
* @newChar: character to replace old char
* Return: the modified buffer
*/

char *replaceChar(char *buffer, char oldChar, char newChar)
{
	char *newBuffer = customStrDup(buffer);
	int i;

	for (i = 0; newBuffer[i]; i++)
	{
		if (newBuffer[i] == oldChar)
			newBuffer[i] = newChar;
	}
	return (newBuffer);
}
