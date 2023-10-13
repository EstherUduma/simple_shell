#include "shell.h"

/**
* displayPrompt - this function displays the shell prompt
*/

void displayPrompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$  ", 2);
	}
}

/**
* processUserInput - process user input and handle commands.
*/

void processUserInput(void)
{
	char *userInput;

	while (1)
	{
		displayPrompt();
		userInput = customGetLine();

		if (userInput == NULL)
		{
			exit(EXIT_SUCCESS);
		}

		trimTrailingSpaces(userInput);

		if (userInput[0] != '\0' && customStringCompare(userInput, "\n") != 0)
		{
			processCommand(userInput);
		}

		free(userInput);
	}
}

/**
* processCommand - process a user command
* @cmd: the user command
*/

void processCommand(char *cmd)
{
	int num_args;
	char *alias_cmd, *full_path;
	char *args[MAX_ARGS];

	if (customStringCompare(cmd, "alias") == 0)
	{
	}
	else if (customStringCompare(cmd, "alias") != 0)
	{
		num_args = customStrtok(cmd, args);

		if (num_args == 3 && customStringCompare(args[1], "alias") == 0)
		{
			alias_name = args[2];
			alias_cmd = args[3];
		}
		else
		{
			full_path = customWhich(cmd);

			if (full_path != NULL)
			{
				write(STDOUT_FILENO, full_path, customStringLength(full_path));
				write(STDOUT_FILENO, "\n", 1);
				free(full_path);
			}
		}
	}
}

/**
* main - entry point of the function
* Return: 0
*/

int main(void)
{
	processUserInput();

	return (0);
}
