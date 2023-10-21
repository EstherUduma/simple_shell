#include "shell.h"

/**
* customGetLine - reads user input from the stdin and returns it as a string
* @userInput: pointer to the userInput String
* @bufferSize: pointer to store the size of the buffer
* @stream: the input stream stdin
* Return: userInput
*/

char *customGetLine(char **userInput, size_t *bufferSize, FILE *stream)
{
	size_t buffer_size = BUFFER_SIZE;
	char c, *buffer = (char *)malloc(sizeof(char) * buffer_size);
	size_t buffer_index;
	ssize_t bytesRead = read(STDIN_FILENO, &c, 1);
	(void)userInput, (void)bufferSize, (void)stream;

	if (buffer == NULL)
	{
		perror("Error: ");
		return (NULL);
	}
	while (1)
	{
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
		handleHashHelper(buffer + buffer_index, &buffer_index);
	}
}

/**
* handleHashHelper - function helps the handleHash function in customGetLin
* @buffer: pointer to the buffer to check the process
* @buffer_index: pointer to the current index within the buffer
*/

void handleHashHelper(char *buffer, size_t *buffer_index)
{
	if (*buffer == '#')
	{
		handleHash(buffer);
		*buffer_index = 0;
	}
}

/**
* handleHash - this function replaces the characters after '#'
* with a null terminatior
* @text: the input string to process
*/

void handleHash(char *text)
{
	int i;

	for (i = 0; text[i] != '\0'; i++)
	{
		if (text[i] == '#')
		{
			text[i] = '\0';
			break;
		}
	}
}
