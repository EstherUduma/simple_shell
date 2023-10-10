#include "shell.h"

/**
* customGetLine - reads user input from the stdin and returns it as a string
* Return: userInput
*/

char *customGetLine(void)
{
	char *userInput = NULL;
	size_t inputSize = 0;
	ssize_t bytesRead;

	bytesRead = getline(&userInput, &inputSize, stdin);

	if (bytesRead == -1)
	{
		perror("Error: ");
		free(userInput);
		return (NULL);
	}

	if (bytesRead == 1)
	{
		free(userInput);
		return ("");
	}

	if (userInput[bytesRead - 1] == '\n')
	{
		userInput[bytesRead - 1] = '\0';
	}

	return (userInput);
}
