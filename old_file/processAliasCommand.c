#include "shell.h"

/**
* _write - Writes data to a file descriptor
* @fd: file descriptor
* @buf: pointer to the data buffer
* @count: number of bytes to write
* Return: the number of bytes written, or -1 on error
*/

ssize_t _write(int fd, const void *buf, size_t count)
{
	return (write(fd, buf, count));
}

/**
* listAliases - lists predefines aliases
*/

void listAliases(void)
{
	static Alias aliases[] = {
		{"l", "ls -CF", NULL},
		{"la", "ls -A", NULL},
		{"ll", "ls -alF", NULL}
	};
	int i = 0;

	while (aliases[i].name != NULL)
	{
		write(STDOUT_FILENO, "alias ", 6);
		write(STDOUT_FILENO, aliases[i].name, customStringLength(aliases[i].name));
		write(STDOUT_FILENO, "='", 2);
		write(STDOUT_FILENO, aliases[i].aliasCmd, customStringLength
		(aliases[i].aliasCmd));
		_write(STDOUT_FILENO, "'\n", 2);
		i++;
	}
}

/**
* defineAlias - defines a new aliasor displays an existing one
* @aliasName: Name of the alias
* @aliasCmd: Alias command
* Return: 0 if alias found and printed, 1 if not found
*/

int defineAlias(char *aliasName, const char *aliasCmd __attribute__((unused)))
{
	static Alias aliases[] = {
		{"l", "ls -CF", NULL},
		{"la", "ls -A", NULL},
		{"ll", "ls -alF", NULL}
	};
	int i = 0;

	for (i = 0; aliases[i].name != NULL; i++)
	{
		if (customStringCompare(aliasName, aliases[i].name) == 0)
		{
			write(STDOUT_FILENO, "alias ", 6);
			write(STDOUT_FILENO, aliases[i].name, customStringLength
			(aliases[i].name));
			write(STDOUT_FILENO, "='", 2);
			write(STDOUT_FILENO, aliases[i].aliasCmd, customStringLength
			(aliases[i].aliasCmd));
			write(STDOUT_FILENO, "'\n", 2);

			return (0);
		}
	}

	return (1);
}

/**
* processAliasCmd - this processes alias related commands
* @args: command arguments
* @numArgs: number of arguments
* Return: 1 if alias command is processed and 0 if not
*/

int processAliasCmd(char *args[MAX_ARGS], int numArgs __attribute__((unused)))
{
	if (customStringCompare(args[0], "alias") != 0)
	{
		return (1);
	}
	if (numArgs == 1)
	{
		listAliases();
	}
	if (args[1] != NULL)
	{
		if (customHasEqualSign(args[1]) && numArgs == 2)
		{
		}
		else if (customHasEqualSign(args[1]) == 0 && numArgs == 2)
		{
			defineAlias(args[1], args[2]);
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
