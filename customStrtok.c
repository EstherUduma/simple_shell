#include "string.h"
#define MAX_ARGS 100
/**
* customStrtok - this function tokenizes a string into substrings
* @str: the string to tokenize
* @delim: the delimeter to split the string
* Return: token
*/

char *customStrtok(char *str, const char *delim)
{
	static char *currentToken;
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

/**
* customStrTok - tokenize
* @command: the string
* @argv: the array
*/

void customStrTok(char *command, char *argv[MAX_ARGS])
{
	char *customtok = customStrtok(command, " ");
	int i;

	for (i = 0; customtok != NULL && i < MAX_ARGS; i++)
	{
		argv[i] = customtok;
		customtok = customStrtok(NULL, " ");
	}
	argv[MAX_ARGS - 1] = NULL;
}
