#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>

/**
* struct list - path dir list struct
* @dir: dir path
* @next: pointer to the next dir
*/

typedef struct list
{
	char *dir;
	struct list *next;
} list_t;

int checkSyntax(char *buffer);
int checkBuiltin(char *command);
int runBuiltins(char **input, char **env);
void printHelp(char **input);
list_t *createPathList(char **env);
list_t *buildPathList(char **environ);
list_t *addPath(list_t **pathList, char *dir);
void freePathList(list_t *pathList);
char **createArgv(char *inputBuffer, list_t **pathList);
char *getPath(char *buffer, list_t **pathList);
char *auxGetPath(list_t *listPointer, char *slashCommand, char *slashInput,
char *input);
char *cleanSpaces(char *buffer);
void freeArgv(char **argv);
int customStrLength(const char *str);
char *customStrCopy(char *destination, const char *source);
char *customStrDup(const char *input_str);
char *customStringCat(char *destination, const char *source);
char *customStrConcat(const char *str1, const char *str2);
char *removeComments(char *buffer);
int isNotEmpty(char *inputBuffer);
int areEqualStrings(char *str1, char *str2);
int countCharOccurrences(char *buffer, char c);
char *replaceChar(char *buffer, char oldChar, char newChar);
void ctrlC(__attribute__((unused)) int a);
void printError(char *programName, char *input, int errorNum);

#endif
