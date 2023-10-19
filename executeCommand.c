#include "shell.h"

/**
* executeCommand - executes a given command
* @arguments: an array of command arguments
*/

void executeCommand(char **arguments)
{
	char error[50];
	int status;

	customStringCopy(error, arguments[0]);

	if (arguments[0][0] == '/')
	{
		if (customcheck(arguments, error))
		{
			return;
		}
	}
	else
	{
		if (customcheck(arguments, error))
		{
			return;
		}
	}
	wait(&status);

	if (WIFEXITED(status))
	{
		ex_code = WEXITSTATUS(status);
	}
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

void printError(char *error, char *command)
{
	ex_code = 127;
	printString(error);
	printString(": ");
	printString("Command not found: ");
	printString(command);
	printString("\n");
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
