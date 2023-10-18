#include "shell.h"

/**
* setEnvVar - this function sets or updates a new environnment variable
* @head: pointer to the head of the linked list
* @name: the name of the environment variable
* @value: the value of the environment variable
*/

void setEnvVar(struct Node **head, const char *name, const char *value)
{
	struct Node *nodeNode = new_node(NULL);
	size_t nameLen = customStringLength(name);
	size_t valueLen = customStringLength(value);

	newNode->str = malloc(nameLen + valueLen + 2);
	if (newNode->str == NULL)
	{
		free(newNode);
		return;
	}

	custom_memcpy(newNode->str, name, nameLen);
	newNode->str[nameLen] = '=';
	custom_memcpy(newNode->str + nameLen + 1, value, valueLen);
	newNode->str[nameLen + valueLen + 1] = '\0';

	remEnvVar(head, name);
	add_node(head, newNode);
}

/**
* remEnvVar - remove an environment variable
* @head: a pointer to the head of the linked list
* @name: the name of the environment variable to be removed
*/

void remEnvVar(struct Node **head, const char *name)
{
	struct Node *current = *head;
	struct Node *prev = NULL;

	while (current != NULL)
	{
		size_t nameLen = customStringLength(name);

		if (customStringCompare(current->str, name, nameLen) == 0 &&
			current->str[nameLen] == '=')
		{
			if (prev != NULL)
			{
				prev->next = current->next;
			}
			else
			{
				*head = current->next;
			}
			free(current->str);
			free(current);
			return;
		}
		prev = current;
		current = current->next;
	}
}

/**
* updateEnviron - update the environ variable
* @head: the head of the linked list
*/

void updateEnviron(struct Node *head)
{
	struct Node *current = head;
	char **newEnviron = malloc(sizeof(char *));
	size_t count = 0;

	while (current != NULL)
	{
		newEnviron = custom_realloc(newEnviron, (count + 2) * sizeof(char *));
		if (newEnviron == NULL)
		{
			return;
		}
		newEnviron[count] = current->str;
		newEnviron[count + 1] = NULL;
		count++;
		current = current->next;
	}
	environ = newEnviron;
}
