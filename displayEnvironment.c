#include "shell.h"

/**
* printEnvironment - Print the contents of the environment variables
* @head: the head of the linked liset
* Return: nothing
*/

void printEnvironment(struct Node *head)
{
	while (head != NULL)
	{
		write(STDOUT_FILENO, head->str, customStringLength(head->str));
		write(STDOUT_FILENO, "\n", 1);
		head = head->next;
	}
}

/**
* freeEnvironmentList - Frees memory allocated for each node in the linked list
* @head: the head of the linked list
* Return: nothing
*/

void freeEnvironmentList(struct Node *head)
{
	struct Node *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
* displayEnvironment - Display the environment variables
* Return: 0
*/

int displayEnvironment(void)
{
	char **env;
	struct Node *head = NULL;

	for (env = environ; *env != NULL; env++)
	{
		add_node(&head, new_node(*env));
	}

	printEnvironment(head);
	freeEnvironmentList(head);
	return (0);
}

/**
* setEnvironmentVariable - set an environment variable
* @name: the name of the environment variable
* @value: the value to be set
* Return: 0
*/

int setEnvironmentVariable(const char *name, const char *value)
{
	char **env;
	struct Node *head = NULL;

	for (env = environ; *env != NULL; env++)
	{
		addNode(&head, newNode(*env));
	}
	setEnvVar(&head, name, value);
	updateEnviron(head);
	freeEnvironmentList(head);

	return (0);
}

/**
* unsetEnvironmentVariable - Delete an environment variable
* @name: the name of the environment variable
* Return: 0 on success and -1 on failure
*/

int unsetEnvironmentVariable(const char *name)
{
	char **e;
	char **env;
	size_t len = customStringLength(name);

	for (env = environ; *env != NULL; env++)
	{
		if (customStringCompare(*env, name, len) == 0 && (*env)[len] == '=')
		{
			for (e = env; *e != NULL; e++)
			{
				*e = *(e + 1);
			}
			return (0);
		}
	}
	return (-1);
}
