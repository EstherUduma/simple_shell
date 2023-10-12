#include "shell.h"
#include <stdlib.h>

/**
* customGetEnv - get the value of an environment variable
* @name: name of the environment variable
* Return: value  of the environment variable
*/

char *customGetEnv(const char *name)
{
	int count;
	char *value;

	for (count = 0; environ[count] != NULL; count++)
	{
		if (customStringCompare(environ[count], name) == 0)
		{
			value = environ[count] + customStringLength(name) + 1;
			return (value);
		}
	}
	return (NULL);
}
