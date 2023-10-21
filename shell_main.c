#include "EstherAnnUduma.h"

/**
* main- the main eenty
* @ac: arg count
* @av: arg vec
* @env: env
* Return: 0
*/

int main(__attribute__((unused)) int ac, char **av, char **env)
{
	list_t *path;
	char *program_name = av[0];
	int aux, node = 0;

	signal(SIGINT, SIG_IGN);
	path = listPath(env);
	if (isatty(0))
		node = 1;
	aux = startShell(path, env, program_name, mode);
	freeList(path)
	return (aux);
}

/**
* startShell - runs the shell interactive
* @path: pointer
* @env: env
* @program_name: argv[0]
* @node: interactive or non-interactive
* Return: 0
*/

int startShell(list_t *path, char **env, char *program_name, int node)
{
	char *buffer = NULL;
	int status, lineStatus;
	size_t len = 0;

	while (1)
	{
		if (node == 1)
			write(STDOUT_FILENO, "hsh# ", 5);
		signal(SIGINT, ctrlC);
		lineStatus = getline(&buffer, &len, stdin);
		if (lineStatus == -1)
		{
			if (lineStatus == EOF)
			{
				free(buffer);
				if (node == 1)
					write(STDOUT_FILENO, "\n", 1);
				return (status);
			}
			printError(program_name, buffer, 3);
		}
		status = executeBuffer(buffer, path, env, program_name);
		if (status == -1 || status == 127 || status == 2)
		{
			if (status == -1)
				perror("Command not found");
			free(buffer);
			break;
		}
	}
	return (status);
}

/**
* executeBuffer - executes a command line
* @buffer: command line
* @path: pointer
* @env: env
* @program_name: argv[0]
* Return: 0
*/

int executeBuffer(char *buffer, list_t *path, char **env, char *program_name)
{
	char *bufferTr, *inputBuffer, *newBuffer;
	int aux, final, exeResult = 0;

	bufferTr = removeComments(buffer);
	inputBuffer = replaceChar(bufferTr, '\t', ' ');
	if (isNotEmpty(inputBuffer))
	{
		final = countCharOccurrences(inputBuffer, ':');
		if (final > 1)
		{
			aux = checkSyntax(inputBuffer);
			if (aux == -1)
			{
				printError(program_name, inputBuffer, 2);
				free(inputBuffer);
				return (-1);
			}
			newBuffer = replaceChar(inputBuffer, ':', '\n');
		}
		else
			newBuffer = customStrDup(inputBuffer);
		exeResult = executeCommand(newBuffer, path, env, final, program_name);
		free(newBuffer);
	}
	free(inputBuffer);
	free(bufferTr);
	return (exeResult);
}

/**
* executeCommand - run command
* @newBuffer: command line
* @path: pointer
* @env: env
* @final: total ;
* @program_name: argv[0]
* Return: 0
*/

int executeCommand(char *newBuffer, list_t *path, char **env, int final, char
*program_name)
{
	char *tmpBuffer, *currentBuffer, **input;
	int i, aux, current, exeResult = 0;

	current = 0;
	while (current < final)
	{
		tmpBuffer = customStrDup(newBuffer);
		currentBuuffer = strtok(tmpBuffer, "\n");
		for (i = 0; i < current; i++)
			currentBuffer = strtok(NULL, "\n");
		input = createArgv(currentBuffer, &path);
		aux = runBuiltins(input, env);
		if (aux == 2)
		{
			free(tmpBuffer);
			return (2);
		}
		if (aux == 0)
		{
			exeResult = executeFork(input, program_name);
		}
		freeArgv(input);
		free(tmpBuffer);
		current++;
	}
	return (exeResult);
}

/**
* executeFork - aux function
* @input: argv
* @program_name: argv[0]
* Return: 0
*/

int executeFork(char **input, char *program_name)
{
	int status, exeResult = 0;
	struct stat statStatus;
	pid_t pid = getpid();

	pid = fork();
	if (pid == 0)
	{
		if (execve(input[0], input, NULL) == -1)
		{
			printError(program_name, input[0], 127);
			exeResult = 127;
		}
	}
	else
	{
		wait(&status);
		if (stat(input[0], &statStatus) == -1)
			exeResult = 127;
	}
	return (exeResult);
}
