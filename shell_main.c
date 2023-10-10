#include "shell.h"

/**
* main - the entry point of the program
* Return: 0
*/

int main(void)
{
	char *userInput;
	char prompt[] = "$ ";

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, prompt, 2);
		}
		userInput = customGetLine();

		if (userInput == NULL)
		{
			exit(EXIT_SUCCESS);
		}

		if (userInput[0] != '\0' && customStringCompare(userInput, "\n") != 0)
		{
			write(STDOUT_FILENO, userInput, customStringLength(userInput));
		}

		free(userInput);
	}

	return (0);
}
