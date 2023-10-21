#include "shell.h"

/**
* removeWhiteSpaces - removes leading and trailing white spaces
* @text: the string to temove white spaces from
*/

void removeWhiteSpaces(char *text)
{
	int dest = 0, spaceCount = 0, source;

	if (text == NULL)
		return;
	for (source = 0; text[source] != '\0'; source++)
	{
		if (!isWhiteSpace(text[source]))
		{
			text[dest++] = text[source];
			spaceCount = 0;
		}
		else if (spaceCount == 0)
		{
			text[dest++] = text[source];
			spaceCount = 1;
		}
	}
	text[dest] = '\0';
}

/**
* readInputLine - read a line of input from the user
* Return: a pointer to the user's input string
*/

char *readInputLine(void)
{
	char *userInput = NULL;
	size_t bufferSize = 0;
	ssize_t inputLength;

	getline(&userInput, &bufferSize, stdin);
	/**customGetLine(&userInput, &bufferSize, stdin);*/
	if (userInput != NULL)
	{
		inputLength = customStringLength(userInput);
		if (inputLength > 0 && userInput[inputLength - 1] == '\n')
		{
			userInput[inputLength - 1] = '\0';
		}
	}
	return (userInput);
}

/**
* exitShell - process the exit command and exit the shell
* @argument: the exit argument
* Return: the exit status
*/

int exitShell(char *argument)
{
	int exitStatus = 0;

	if (argument == NULL)
		return (0);
	if (customIsNumber(argument))
		exitStatus = customAtoi(argument);
	else
	{
		printString("exit: Illegal number: ");
		printString(argument);
		printString("\n");
		exitStatus = 2;
	}
	return (exitStatus);
}

/**
* customAtoi - convert a string to an integer
* @str: the input string
* Return: the integer value or 0 if the conversion fails
*/

int customAtoi(char *str)
{
	int result = 0, i = 0, sign = 1;

	if (str == NULL)
		return (0);
	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}
	for (; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		else
		{
			return (0);
		}
	}
	return (result * sign);
}

/**
* customIsNumber - check if a string is a valid number
* @str: the input string to check
* Return: 1 if the string is valid and 0 if not
*/

int customIsNumber(const char *str)
{
	int i  = 0;

	if (str == NULL || *str == '\0')
		return (0);

	if (str[0] == '-')
		i = 1;
	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
