#include "shell.h"

/**
* trimTrailingSpaces - this function removes trailing spaces from a string
* @inputStr: the input string to trim
*/

void trimTrailingSpaces(char *inputStr)
{
	size_t length = customStringLength(inputStr);

	while (length > 0 && inputStr[length - 1] == ' ')
	{
		inputStr[--length] = '\0';
	}
}

/**
* splitIntoArgs - tokenizes a command into arguments
* @inputCommand: the command to be tokenize
* @args: An array to store the resulting arguments
*/

void splitIntoArgs(char *inputCommand, char *args[MAX_ARGS])
{
	int argIndex = 0;
	char *token = customStrtok(inputCommand, " ");

	while (token != NULL)
	{
		args[argIndex++] = token;
		token = customStrtok(NULL, " ");
	}
	args[argIndex] = NULL;
}

/**
* countArguments - counts the number of arguments in an array
* @args: the array if argument
* Return: number of arguments
*/

int countArguments(char *args[])
{
	int argCount = 0;

	while (args[argCount] != NULL)
	{
		argCount++;
	}
	return (argCount);
}

/**
* customHasEqualSign - checks if string contains an equal sign
* @text: the string to check
* Return: 1 if equal and 0 if not
*/

int customHasEqualSign(char *text)
{
	while (*text != '\0')
	{
		if (*text == '=')
		{
			return (1);
		}
		text++;
	}
	return (0);
}

/**
* customExit - this function exits with a status code
* @status: status code to exit with
* @cmdCount: count of command
* @shellName: name of the shell
* @cmdArgs: string of input command arguments
* Return: exit code
*/

int customExit(char *status, int cmdCount, char *shellName, char **cmdArgs)
{
	int exitCode = 0;
	int charIndex = 0;

	if (status != NULL)
	{
		while (status[charIndex])
		{
			if (!(status[charIndex] >= '0' && status[charIndex] <= '9'))
			{
				customError(shellName, cmdCount. cmdArgs[0], cmdArgs[1]);
				exitCode = 2;
				return (500);
			}
			charIndex++;
		}
		exitCode = customAtoi(status);
	}
	return (exitCode);
}
