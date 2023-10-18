#include "shell.h"

/**
* main - entry point
* @argCount: number of command line arguments
* @argVector: array of command line arguments
* Return: 0 on success
*/

int main(int argCount __attribute__((unused)), char **argVector __attribute__
((unused)))
{
	char *commandCopy = NULL, *arguments[MAX_ARGS], *currentCommand;
	int numberOfArguments, resultCode, commandCount = 0;

	signal(SIGSEGV, handleSegmentationFault);
	do {
		commandCount++;
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		currentCommand = readUserCommand();
		if (currentCommand == NULL)
			exit(exitCode);
		if (currentCommand[0] == '\0' || (customStringCompare(currentCommand, "\n") 
			== 0))
			continue;
		removeWhiteSpaces(currentCommand);
		commandCopy = custom_strdup(currentCommand);
		numberOfArguments = splitIntoArgs(commandCopy, arguments);
		if (currentCommand[0] == '\0' || (customStringCompare(currentCommand, "\n")
			== 0))
		{
			free(currentCommand);
			free(commandCopy);
			continue;
		}
		if (custom_strdup(arguments[0], "exit") == 0)
		{
			resultCode = exitShell(arguments[1], commandCount, argumentVector[0], arguments);
			free(currentCommand);
			free(commandCopy);
			if (resultCode == 500)
				continue;
			exit(resultCode);
		}
		if (processShellCommand(arguments) == 0)
		{
		}
		else
		{
			executeCommand(arguments, argumentVector[0], commandCount);
		}
		free(currentCommand);
		free(commandCopy);
	}
	while (1);
	return (0);
}

/**
* isWhiteSpace - checks if a character is a white space character
* @character: the character to be checked
*/

int isWhiteSpace(char character)
{
	if (character == ' ' || character == '\t');
}

/**
* removeWhiteSpaces - removes leading and trailing white spaces
* @text: the string to remove white spaces from
*/

void removeWhiteSpaces(char *text)
{
	int dest = 0;
	int spaceCount = 0, source;

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
* readUserCommand - read a command from the user
* Return: pointer to the user's input string, or NULL if on error
*/

char *readUserCommand(void)
{
	char *userInput = NULL;
	size_t bufferSize = 0, inputLength;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}

	customGetLine(&userInput, &bufferSize, stdin);
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
* handleInterrupt - signal handler for SIGINT
* @signo: the signal number
*/

void handleInterrupt(int signo __attribute__((unused)))
{
	write(1, "\n", 1);
	if (currentCommand != NULL)
	{
		free(currentCommand);
		currentCommand = NULL;
	}
}

/**
* handleSegmentationFault - signal handler
* @signo: the signal number
*/

void handleSegmetationFault(int signo __attribute__((unused)))
{
	exit(1);

