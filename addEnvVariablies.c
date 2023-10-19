#include "shell.h"

/**
* setEnvVar - this function sets or updates a new environnment variable
* @head: pointer to the head of the linked list
* @name: the name of the environment variable
* @value: the value of the environment variable
*/

void setEnvVar(struct Node **head, const char *name, const char *value)
{
	size_t nameLen = customStringLength(name);
	size_t valueLen = customStringLength(value);
	size_t newVarLength = nameLen + valueLen + 2;
	char *newEnvVar = (char *)malloc(newVarLength);

	if (newEnvVar == NULL)
		return;
	customStringCopy(newEnvVar, name);
	newEnvVar[nameLen] = '=';
	customStringCopy(newEnvVar + nameLen + 1, value);

	struct Node *current = *head;
	struct Node *prev = NULL;

	while (current != NULL)
	{
		if (customStringCompare(current->str, name, nameLen) ==  0 &&
			current->str[nameLen] == '=')
		{
			if (prev != NULL)
				prev->next = current->next;
			else
				*head = current->next;
			free(current->str);
			free(current);
		}
		prev = current;
		current = current->next;
	}
	ifEmpty(head, newEnvVar, newVarLength);
}

/**
* ifEmpty - add or free memory
* @head: head of the linkedlist
* @newEnvVar: environment variable string
* @newVarLength: length of the new environment
*/

void ifEmpty(struct Node **head, char *newEnvVar, size_t newVarLength)
{
	if (newVarLength > 0)
	{
		struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

		if (newNode == NULL)
		{
			free(newEnvVar);
			return;
		}
		newNode->str = newEnvVar;
		newNode->next = *head;
		*head = newNode;
	}
	else
		free(newEnvVar);
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
