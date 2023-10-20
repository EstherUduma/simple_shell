#include "shell.h"

/**
* executeCommand - executes a given command
* @args: an array of command arguments
* @argv: the program name
* @i: the command count
*/

void executeCommand(char **args, char *argv, int i)
{
	char *curCmd, error[50];
	int status;

	customStringCopy(error, argv);
	ex_code = 0;
	do {
		if (args[0][0] == '/')
		{
			if (customcheck(args, NULL, error, i, environ))
				break;
		}
		else
		{
			if (args[0][0] != '.')
			{
				curCmd = customWhich(args[0]);
				if (curCmd == NULL)
				{
					printError(error, i, args[0]);
					break;
				}
				if (customcheck(args, curCmd, error, i, environ))
				{
					free(curCmd);
					break;
				}
				free(curCmd);
			}
			else
			{
				curCmd = args[0];
				if (customcheck(args, curCmd, error, i, environ))
					break;
			}
		}
		wait(&status);
		if (WIFEXITED(status))
			ex_code = (WEXITSTATUS(status));
	} while (0);
}






/**
* executeWithExecve- executes a command with execve and handles errors
* @command: the command to execute
* @p: array of command parameters
* @env: environment variables
*/

void executeWithExecve(char *command, char **p, char **env)
{
	if (execve(command, p, env) == -1)
	{
		ex_code = 127;
	}
	ex_code = 1;
}

/**
*  printError - prints error message
* @error: the error message to print
* @command: the command associated with the error
*/

void printError(char *error, int i, char *command)
{
	ex_code = 127;
	printString(error);
	printString(": ");
	printNumber(i);
	printString(": ");
	printString(command);
	printString(": Command not found\n");
}

/**
* printString - prints a string
* @str: string to print
*/

void printString(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
* printNumber - prints an integer
* @n: the integer to print
*/

void printNumber(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = (n * -1) - 1;
	}
	if (n == 0)
	{
		_putchar('0');
	}
	else
	{
		int digits[10];
		int i = 0;

		while (n > 0)
		{
			digits[i] = n % 10;
			n /= 10;
			i++;
		}

		while (i > 0)
		{
			i--;
			_putchar(digits[i] + '0');
		}
	}
}
