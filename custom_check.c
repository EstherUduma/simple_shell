#include "shell.h"

/**
* customcheck - checks file access and runs the command
* @cmd_args: array of commands
* @error_msg: error message string
* Return: 0
*/

int customcheck(char **cmd_args, char *error_msg)
{
	if (access(cmd_args[0], X_OK) == 0)
	{
		if (fork() == 0)
		{
			customexecve(cmd_args[0], cmd_args, environ);
		}
		return (0);
	}
	else
	{
		_perror(error_msg);
		return (1);
	}
}

/**
* _putchar - writes a character to standard error
* @character: character to print
* Return: 1 on successful write
*/

int _putchar(char character)
{
	return (write(2, &character, 1));
}
