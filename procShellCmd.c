#include "shell.h"

/**
* procShellCmd - process and execute shell commands
* @arguments: array  of strings
* Return: 0 on success and 1 if not
*/

int procShellCmd(char **arguments)
{
	int argumentCount = countArguments(arguments);

	if (customStringCompare(arguments[0], "cd") == 0 && argumentCount >= 1)
	{
		changeDirectory(arguments[1]);
		return (0);
	}
	if (customStringCompare(arguments[0], "env") == 0)
	{
		printEnvironment();
		return (0);
	}
	if (customStringCompare(arguments[0], "setenv") == 0 && argumentCount == 3)
	{
		setEnvironmentVariable(arguments[1], arguments[2]);
		return (0);
	}
	if (customStringCompare(arguments[0], "unsetenv") == 0 && argumentCount == 2)
	{
		unsetEnvironmentVariable(arguments[1]);
		return (0);
	}
	return (1);
}

/**
* printShellErr - print error message for illegal numbers
* @shellName: name of the shell
* @cmdCount: number of commands
* @cmdName: name of the command
* @cmdArg: arg of the command
*/

void printShellErr(char *shellName, int cmdCount, char *cmdName, char *cmdArg)
{
	printString(shellame);
	printString(": ");
	printNumber(cmdCount);
	printString(": ");
	printString(cmdName);
	printString(": Illegal number: ");
	printString(cmdArg);
	printString("\n");
}
