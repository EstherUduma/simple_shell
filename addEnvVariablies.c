#include "shell.h"

/**
* setEnvVar - this function sets or updates a new environnment variable
* @head: pointer to the head of the linked list
* @name: the name of the environment variable
* @value: the value of the environment variable
*/

void setEnvVar(struct Node **head, const char *name, const char *value)
{
	struct Node {
		char *str;
		struct Node *next;
	};
	struct Node new_node = malloc(sizeof(struct Node));
	size_t nameLen = customStringLength(name);
	size_t valueLen = customStringLength(value);

	new_node->str = malloc(nameLen + valueLen + 2);
	if (new_node->str == NULL)
	{
		free(new_node->str);
		free(new_node);
		return;
	}

	custom_memcpy(new_node->str, name, nameLen);
	new_node->str[nameLen] = '=';
	custom_memcpy(new_node->str + nameLen + 1, value, valueLen);
	new_node->str[nameLen + valueLen + 1] = '\0';

	remEnvVar(head, name);
	add_node(head, new_node);
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
