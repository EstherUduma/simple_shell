#include "shell.h"

/**
* handleSegfault - signal handler for SIGSEGv
* @signo: the signal number
*/

void handleSegfault(int signo __attribute__((unused)))
{
	exit(1);
}

/**
* main - entry point of the program
* @argCnt: the number of command line arguments
* @argVct: an array of command line arguments
* Return: 0 on success
*/

int main(int argCnt, char **argVct)
{
	signal(SIGSEGV, handleSegfault);
	do {
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		curCmd = readUserCommand();
		if (curCmd == NULL)
			exit(exCode);
		if (curCmd[0] == '\0' || customStringCompare(curCmd, "\n") == 0)
		{
			free(curCmd);
			free(commandCopy);
			continue;
		}
		if (customStringCompare(args[0], "exit") == 0)
		{
			int rsltCode = exitShell(args[1], argCnt, argVec, args);

			free(curCmd);
			free(commandCopy);
			if (rsltCode == 500)
				continue;
			exit(rsltCode);
		}
		if (processCommand(args) == 0)
		else
			executeCommand(args, argVector[0], curCmd);
		free(curCmd);
		free(commanfCopy);
	} while (1);
	return (0);
}

/**
* handleInterrupt - signal handler for SIGINT
* @signo: the signal number
*/

void handleInterrupt(int signo __attribute__((unused)))
{
	write(1, "\n", 1);
	if (curCmd != NULL)
	{
		free(curCmd);
		curCmd = NULL;
	}
}

/**
* readUserCommand - reads a command from the user
* Return: a pointer to the users input string or NULL if error
*/

char *readUserCommand(void)
{
	char *userInput;

	userInput = readInputLine();
	signal(SIGINT, handleInterrupt);
	return (userInput);
}

/**
* isWhiteSpace - checks if a character is a white space character
* @character: the character to be checked
* Return: 0
*/

int isWhiteSpace(char character)
{
	if (character == ' ' || character == '\t')
	{
		return (1);
	}
	return (0);
}
