#include "shell.h"

/**
* customGetLine - reads user input from the stdin and returns it as a string
* Return: userInput
*/

char *customGetLine(void)
{
	ssize_t bytesRead;
	char *buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	size_t buffer_size;

	if (buffer == NULL)
	{
		perror("Error: ");
		return (NULL);
	}

	buffer_size = BUFFER_SIZE;
	bytesRead = getline(&buffer, &buffer_size, stdin);

	if (bytesRead == -1)
	{
		perror("Error: ");
		free(buffer);
		return (NULL);
	}

	if (bytesRead == 1)
	{
		free(buffer);
		return ("");
	}

	if (buffer[bytesRead - 1] == '\n')
	{
		buffer[bytesRead - 1] = '\0';
	}

	return (buffer);
}
