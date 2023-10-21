#include "EstherAnnUduma.h"

/**
* createPathList - create a linked list inthe path
* @env: environment variables
* Return: a pointer to the new list
*/
list_t *createPathList(char **env)
{
	list_t *pathList = NULL;
	char **ennvironCopy;
	int length, i;

	length = 0;
	while (env[length])
		length++;
	environCopy = malloc(sizeof(char *) * length);
	if (!environCopy)
	{
		perror("MALLOC");
		return (NULL);
	}
	i = 0;
	while (env[i])
	{
		environCopy[i] = customStrDup(env[i]);
		i++
	}
	pathList = buildPathList(environCopy);
	i = 0;
	while (i < length)
	{
		free(environCopy[i]);
		i++;
	}
	free(environCopy);
	return (pathList);
}

/**
* buildPathList - build a linkedlist  with dir from the path
* @environ: environment variables
* Return:  a pointer to the new list
*/

list_t *buildPathList(char **environ)
{
	list_t *pathList = NULL, *temp = NULL;
	char *dir, *aux, *varName, *varValue = NULL;
	int i;

	i = 0;
	while (environ[i])
	{
		varName = strtok(environ[i], "=");
		if (areEqualStrings(varName, "PATH") == 0)
		{
			varValue = strtok(NULL, "\n");
			break;
		}
		i++;
	}
	if (varValue)
	{
		i = 0;
		aux = strtok(varValue, ":");
		if (aux)
		{
			dir = customStrDup(aux);
			pathList = addPath(&pathList, dir);
			aux = strtok(NULL, ":");
		}
		temp = pathList;
		while (aux)
		{
			i++;
			dir = customStrDup(aux);
			addPath(&pathList, dir);
			temp = temp->next;
			aux = strtok(NUL, ":");
		}
	}
	else
		perror("ERROR: varValue NULL\n");
		return (pathList);
}

/**
* addPath - adds a new node to the path
* @pathList: pointer to the list
* @dir: directory to be placed in the node
* Return: pointer to the list
*/

list_t *addPath(list_t **pathList, char *dir)
{
	list_t *newNode, *current = *pathList;

	newNode = malloc(sizeof(list_t));
	if (newNode == NULL)
	{
		perror("ERROR: unable to allocate memory\n");
		return (NUL);
	}
	newNode->dir = dir;
	newNode->next = NULL;
	if (current)
	{
		while (current->next)
			current = current->next;
		current->next = newNode;
	}
	else
		*pathList = newNode;
	return (newNode);
}

/**
* freePathList - free the ist of dirs
* @pathList: pointer to the list
*/

void freePathList(list_t *pathList)
{
	list_t *currentNode;
	list_t *nextNode;

	if (pathList)
	{
		currentNode = pathList;
		nextNode = pathList->next;
		while (nextNode)
		{
			free(currentNode->dir);
			free(currentNode);
			currentNode = nextNode;
			nextNode = nextNode->next;
		}
		free(currentNode->dir);
		free(CurrentNode);
	}
}
