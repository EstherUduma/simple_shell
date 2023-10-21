#include "EstherAnnUduma.h"

/**
* ctrlC - signa handler for ctrl and prints a new line
* @a: unused parameter
*/

void ctrlC(__attribute__((unused)) int a)
{
	signal(SIGINT, ctrlC);
	write(1, "\n", 1);
	write(STDOUT_FILENO, "EstherAnnUduma> ", 9);
}

/**
* printError - prints the error to the stdout
* @programName: the name of the program
* @input: the command that produced the error
* @errorNum: the number of the error type
*/

void printError(char *programName, char *input, int errorNum)
{
	if (errorNum == 127)
	{
		write(STDOUT_FILENO, programName, customStrLength(programName));
		write(STDOUT_FILENO, ": 1: ", 5);
		write(STDOUT_FILENO, input, customStrLength(input));
		write(STDOUT_FILENO, ": not found\n", 12);
	}
	if (errorNum == 2)
	{
		write(STDOUT_FILENO, "sh: 1: Syntax error: \"", 23);
		write(STDOUT_FILENO, input, customStrLength(input));
		write(STDOUT_FILENO, "\" unexpected\n", 13);
	}
	if (errorNum == 3)
	{
		write(STDOUT_FILENO, programName, customStrLength(programName));
		write(STDOUT_FILENO, ": 1: internal error allocating memory\n", 38);
	}
}
