#include "shell.h"

/**
* customGetLine - reads user input from the stdin and returns it as a string
* Return: userInput
*/

char *customGetLine(void)
{
	ssize_t bytesRead;
	char c;
	size_t buffer_size = BUFFER_SIZE;
	char *buffer = (char *)malloc(sizeof(char) * buffer_size);
	size_t buffer_index;

	if (buffer == NULL)
	{
		perror("Error: ");
		return (NULL);
	}
	while (1)
	{
		bytesRead = read(STDIN_FILENO, &c, 1);
		if (bytesRead == 0 || c == EOF || c == '\n')
		{
			if (buffer_index == 0)
			{
				free(buffer);
				return ("");
			}
			buffer[buffer_index] = '\0';
			return (buffer);
		}
		buffer[buffer_index] = c;
		buffer_index++;
		if (buffer_index >= BUFFER_SIZE)
		{
			char *newBuffer = (char *)realloc(buffer, sizeof(char) * (buffer_size +
			BUFFER_SIZE));

			if (newBuffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
			buffer = newBuffer;
			buffer_size += BUFFER_SIZE;
		}
	}
}
