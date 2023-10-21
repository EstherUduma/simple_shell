#include "EstherAnnUduma.h"

/**
* checkSyntax - checks if the command syntax is correct
* @buffer: buffer to check
* Return: 0 if successful and -1 if not
*/

int checkSyntax(char *buffer)
{
	int flag = 0, i, syntax_error = 0;

	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] == ';' && flag == 1)
		{
			syntax_error = -1;
			break;
		}
		else if (buffer[i] == ';' && flag == 0)
		{
			flag = 1;
		}
		else if (buffer[i] == ';' && buffer[i] != ' ' && flag == 1)
		{
			flag = 0;
		}
	}
	return (syntax_error);
}
/**
* checkBuiltin - checks if a command id built in
* @command: command to check
* Return: 0 if buuilt in and -1 if not
*/

int checkBuiltin(char *command)
{
	if (!areEqualStrings(command, "exit"))
		return (0);
	if (!areEqualStrings(command, "env"))
		return (0);
	if (!areEqualStrings(command, "help"))
		return (0);
	return (-1);
}

/**
* runBuiltins - executes built ins
* @input: command input
* @env: environment variables
* Return: 0 if not and 1 if
*/

int runBuiltins(char **input, char **env)
{
	char *str;
	int i;

	if (!areEqualStrings(input[0], "exit"))
	{
		freeArgv(input);
		return (2);
	}
	if (!areEqualStrings(input[0], "help"))
	{
		printHelp(input);
		return (1);
	}
	if (!areEqualStrings(input[0], "env"))
	{
		for (i = 0; env[i]; i++)
		{
			str = env[i];
			write(STDOUT_FILENO, str, customStrLength(str));
			write(STDOUT_FILENO, "\n", 1);
		}
		return (1);
	}
	return (0);
}

/**
* printHelp - prints help
* @input: command input
*/

void printHelp(char **input)
{
	char *str;

	if (input[1] != NULL)
	{
		if (!areEqualStrings(input[1], "help"))
		{
			str = "help: help [pattern ...]\n";
			write(STDOUT_FILENO, str, customStrLength(str));
			str = "\tDisplays brief summaries of built in comands.\n";
			write(STDOUT_FILENO, str, customStrLength(str));
		}
		else if (!areEqualStrings(input[1], "exit"))
		{
			str = "exit: exit\n";
			write(STDOUT_FILENO, str, customStrLength(str));
			str = "\tExit the shell,\n";
			write(STDOUT_FILENO, str, customStrLength(str));
		}
	}
	else
	{
		str = "These shell commands are defined internally.\n";
		write(STDOUT_FILENO, str, customStrLength(str));
	}
}
