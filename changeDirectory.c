#include "shell.h"

/**
* changeDirectory - function changes the current working directory
* @newPath: the path to change
* Return: nothing
*/

void changeDirectory(char *newPath)
{
	char *homeDir = customGetEnv("HOME");
	char *oldWorkingDir = customGetEnv("OLDPWD");
	char *currentWorkingDir = customGetEnv("PWD"), currentDir[1024];

	if (newPath == NULL)
	{
		if (chdir(homeDir) == -1)
		{
			perror("cd");
			return;
		}
		setenv("OLDPWD", currentWorkingDir, 1);
		setenv("PWD", homeDir, 1);
	}
	else if (customStringCompare(newPath, "-") == 0)
	{
		if (oldWorkingDir != NULL)
		{
			if (chdir(oldWorkingDir) == -1)
			{
				perror("cd");
				return;
			}
			setenv("OLDPWD", currentWorkingDir, 1);
			setenv("PWD", oldWorkingDir, 1);
		}
	}
	else
	{
		if (chdir(newPath) == -1)
		{
			perror("cd");
			return;
		}
		getcwd(currentDir, sizeof(currentDir));
		setenv("OLDPWD", currentWorkingDir, 1);
		setenv("PWD", currentDir, 1);
	}
}
