#include "shell.h"

/**
* customcheck - checks file access and runs the command
* @cmd_args: array of commands
* @curCmd: the command to check
* @error: error message
* @i: the command count
* @env: array of environment variables
* Return: 0 if successful and 1 if not
*/

int customcheck(char **cmd_args, char *curCmd, char *error, int i, char **env)
{
	pid_t idk;
	char *m = NULL;

	do {
		m = (curCmd == NULL) ? cmd_args[0] : curCmd;
		if (access(m, X_OK) == 0)
		{
			idk = fork();
			if (idk == 0)
				execve(m, cmd_args, env);
			return (0);
		}
		else
		{
			printError(error, i, m);
			return (1);
		}
	} while (0);
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
