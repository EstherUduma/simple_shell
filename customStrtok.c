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
	char *token;
	int size = 0, i = 0;

	if (str != NULL)
	{
		currentToken = str;
	}
	while (currentToken[i] != '\0')
		if (currentToken[i] ==  *delim)
		{
			currentToken[i] = '\0';
			token = currentToken;
			currentToken = &currentToken[i + 1];
			return (token);
		}
		else
			i++;
	if (currentToken[0] != '\0')
	{
		while (currentToken[size] != 0)
			size++;
		token = currentToken;
		currentToken = currentToken + size;
		return (token);
	}
	return (NULL);
}

/**
* customStrTok - tokenize
* @command: the string
* @argv: the array
*/

void customStrTok(char *command, char *argv[MAX_ARGS])
{
	char *customtok;
	int i = 0;

	customtok = customStrtok(command, " ");

	while (customtok != NULL)
	{
		argv[i++] = customtok;
		customtok = customStrtok(NULL, " ");
	}
	argv[i] = NULL;
}
