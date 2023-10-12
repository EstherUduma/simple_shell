#include "shell.h"

/**
* main - the entry point of the program
* Return: 0
*/

int main(void)
{
	char *userInput;
	char prompt[] = "$ ";
	char *full_path;

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
			full_path = customWhich(userInput);

			if (full_path != NULL)
			{
				write(STDOUT_FILENO, full_path, customStringLength(full_path));
				write(STDOUT_FILENO, "\n", 1);
				free(full_path);
			}
		}

		free(userInput);
	}

	return (0);
}
