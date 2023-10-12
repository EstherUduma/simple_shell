#include "shell.h"

/**
* processUserInput - process user input
*/

void processUserInput(void)
{
	char *userInput, prompt[] = "$ ", *full_path;

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

		trimTrailingSpaces(userInput);

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
}

/**
* handleAliases - handle alias related commands
*/

void handleAliases(void)
{
	char *cmd, *argv[MAX_ARGS], num_arg;

	do {
		if (isatty(STDIN_FILENO))
		{
			write(1, "$ ", 2);
		}
		cmd = customGetLine();
		trimTrailingSpaces(cmd);
		if (cmd == NULL)
		{
			exit(EXIT_SUCCESS);
		}
		splitIntoArgs(cmd, argv);
		num_arg = num_args(argv);
		alias_command(argv, num_arg);
		free(cmd);
	} while (1);
}

/**
* main - the entry point of the program
* Return: (0)
*/

int main(void)
{
	processUserInput();

	return (0);
}
