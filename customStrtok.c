#include "string.h"

/**
* customStrtok - this function tokenizes a string into substrings
* @str: the string to tokenize
* @delim: the delimeter to split the string
* Return: token
*/

char *customStrtok(char *str, const char *delim)
{
	static char *currentToken = NULL;
	char *token = currentToken;

	if (str != NULL)
	{
		currentToken = str;
	}

	if (currentToken == NULL || *currentToken == '\0')
	{
		return (NULL);
	}

	while (*currentToken != '\0' && !strchr(delim, *currentToken))
	{
		currentToken++;
	}

	if (*currentToken != '\0')
	{
		*currentToken = '\0';
		currentToken++;
	}

	return (token);
}
