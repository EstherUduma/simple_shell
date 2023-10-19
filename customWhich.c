#include "shell.h"

/**
* customWhich - this function finds the path to an executable command in PATH
* @command: the name of the command to search for
* Return: the full path to the executable or NULL if not found
*/

char *customWhich(const char *command)
{
	char *path = customGetEnv("PATH");
	char *dir;
	char full_path[1024];

	if (path == NULL)
	{
		return (NULL);
	}

	while ((dir = customStrtok(path, ":")) != NULL)
	{
		customStringCopy(full_path, dir);
		custom_strcat(full_path, "/");
		custom_strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			return (custom_strdup(full_path));
		}
	}

	return (NULL);
}

/**
* DisplayAllAliases - print all aliases in the list
* @aliases: pointer to the first alias in the list
*/

void DisplayAllAliases(Alias *aliases)
{
	for (alias_t *curAlias = aliases; curAlias; curAlias = curAlias->next)
	{
		defineAlias(curAlias);
	}
}
