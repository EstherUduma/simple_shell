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
			fag = 1;
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

	if (!areEqualStrings(input[0], "exit"))
	{
		freeArgv(input);
		return (2);
