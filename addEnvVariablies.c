#include "shell.h"

/**
* addEnvVar - this function adds or updates an environnment var
* @head: pointer to the head of the linked list
* @name: the name of the environment variable
* @value: the value of the environment variable
*/

void addEnvVar(struct Node **head, const char *name, const char *value)
{
	char *newEnvVar = custom_strcat(name, "=", value);

	if (newEnvVar == NULL)
	{
		return;
	}

