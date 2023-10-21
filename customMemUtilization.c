#include "EstherAnnUduma.h"

/**
* createArgv - converts input_buffer into argument vectors
* @inputBuffer: input buffer to be processed
* @pathList: pointer to the path dir list
* Return: a pointer to the new Argv
*/

char **createArgv(char *inputBuffer, list_t **pathList)
{
	int i = 0, ac = 0, argc = 1;
	char *currentString, *strToPut, *newInput, **argv;

	newInput = getPath(inputBuffer, pathList);

	while (newInput[i])
	{
		if (newInput[i] == ' ' && (newInput[i + 1] && (newInput[i + 1]
			!= ' ' && newInput[i + 1] != '\n')))
			argc += 1;
		i++;
	}
	argv = malloc(sizeof(char *) * (argc + 1));
	if (argv == NULL)
	{
		write(STDOUT_FILENO, "MALLOC ERROR\n", 14);
		return (NULL);
	}
	currentString = strtok(newInput, "\n");
	currentString = strtok(currentString, " ");
	ac = 0;
	while (ac < (argc + 1))
	{
		strToPut = customStrDup(currentString);
		argv[ac] = strToPut;
		currentString = strtok(NULL, " ");
		ac++;
	}
	free(newInput);
	return (argv);
}

/**
* getPath - obtain the directory path where the command is executable
* @buffer: entire command
* @pathList: pointer
* Return: dir with concatenated input buffer
*/

char *getPath(char *buffer, list_t **pathList)
{
	char *input, *aux, *command = NULL;
	char *slashCommand, *slashInput, *inputBuffer;
	struct stat status;
	list_t *listPointer = *pathList;

	inputBuffer = cleanSpaces(buffer);
	input = customStrDup(inputBuffer);
	free(inputBuffer);

	aux = customStrDup(input);
	command = strtok(aux, " ");
	if (command == NULL)
		command = aux;
	else
	{
		if (stat(command, &status) == 0)
		{
			free(aux);
			return (input);
		}
		else if (checkBuiltin(command) == 0)
		{
			free(aux);
			return (input);
		}
	}
	slashCommand = customStrConcat("/", command);
	slashInput = customStrConcat("/", input);
	free(aux);
	return (auxGethPath(listPointer, slashCommand, slashInput, input));
}

/**
* auxGethPath - aux function
* @listPointer: pointer to the dir path ist
* @slashCommand: aux string
* @slashInput: aux string
* @input: input
* Return: dir with concat input
*/

char *auxGetPath(list_t *listPointer, char *slashCommand, char *slashInput,
char *input)
{
	char *aux;
	struct stat status;

	for (; listPointer; listPointer = listPointer->next)
	{
		aux = customStrConcat(listPointer->dir, slashCommand);
		if (stat(aux, &status) == 0)
		{
			aux = customStrConcat(listPointer->dir, slashInput);
			free(input);
			free(slashInput);
			free(slashCommand);
			return (aux);
		}
		free(aux);
	}
	free(slashInput);
	free(slshComand);
	return (input);
}

/**
* cleanSpaces - removes white spaces
* @buffer: buffer to be cleaned
* Return: a buffer without spaces
*/

char *cleanSpaces(char *buffer)
{
	int len, firstCharPosition = 0;
	char *newBuffer, *trueBuffer;

	newBuffer = customStrDup(buffer);

	if (newBuffer[0] != ' ')
		return (newBuffer);
	while (newBuffer[firstCharPosition] == ' ')
		firstCharPosition++;
	len = customStrLength(newBuffer + firstCharPosition);
	trueBuffer = malloc(sizeof(char) * (len + 1));
	if (trueBuffer == NULL)
	{
		free(newBuffer);
		return (NULL);
	}
	customStrCopy(trueBuffer, newBuffer + firstCharPosition);
	free(newBuffer);
	return (trueBuffer);
}

/**
* freeArgv - free memory
* @argv: arg vector
*/

void freeArgv(char **argv)
{
	int i = 0;

	for (i = 0; argv[i] != NULL; i++)
		free(argv[i]);
	free(argv);
}
