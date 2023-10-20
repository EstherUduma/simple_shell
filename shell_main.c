#include "shell.h"

/**
* handleSegfault - signal handler for SIGSEGv
* @signo: the signal number
*/

void handleSegfault(int signo __attribute__((unused)))
{
	exit(1);
}

int ex_code = 0;

/**
* main - entry point of the program
* @argCnt: the number of command line arguments
* @argVct: an array of command line arguments
* Return: 0 on success
*/

int main(int aCnt __attribute__((unused)), char **aVct __attribute__((unused)))
{
	char *curCmdDup, *desDup[MAX_ARGS], *desMain[MAX_ARGS];
	int should_continue = 1, i = 0, rsltCode;

	signal(SIGSEGV, handleSegfault);
	while (should_continue)
	{
		i++;
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		printf("line 34");
		curCmd = readUserCommand();
		printf("%s", curCmd);
		if (curCmd == NULL)
			exit(ex_code);
		if ((customStringCompare(curCmd, "\n") == 0) || curCmd[0] == '\0')
			continue;
		removeWhiteSpaces(curCmd);
		curCmdDup = custom_strdup(curCmd);
		customStrTok(curCmdDup, desDup);
		customStrTok(curCmd, desMain);
		if (customStringCompare(desMain[0], "exit") == 0)
		{
			rsltCode = customExit(desDup[1], i, aVct[0], desMain);
			free(curCmd);
			free(curCmdDup);
			if (rsltCode == 500)
				continue;
			exit(rsltCode);
		}
		if ((customStringCompare(curCmd, "\n") == 0) || curCmd[0] == '\0')
		{
			free(curCmd);
			free(curCmdDup);
			continue;
		}
		printf("line 60");
		if (procShellCmd(desMain) == 0)
		{
			printf("line 63");
		}
		else
			executeCommand(desMain, aVct[0], i);
		printf("line 66");
		free(curCmd);
		free(curCmdDup);
	}
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
