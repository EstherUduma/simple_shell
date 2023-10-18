#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024
#define MAX_ARGS 100

extern char **environ;

/**
* struct Alias - structure to represent an alias
* @name: the name of the alias
* @aliasCmd: the command associated with the the alias
*/
typedef struct Alias
{
	const char *name;
	const char *aliasCmd;
} Alias;

int main(void);
char *customGetLine(void);
char *customStrtok(const char *str, const char *delim);
void *custom_realloc(void *ptr, size_t size);
void *custom_memcpy(void *dst, const void *src, size_t n);
int customStringCopy(char *destination, const char *source);
int customStringLength(const char *str);
int customStringCompare(const char *strA, const char *strB);
char *customGetEnv(const char *name);
char *custom_strdup(const char *input_str);
char *custom_strcat(char *destination, const char *source);
int custom_strncmp(const char *s1, const char *s2, size_t n);
char *customWhich(const char *command);
void trimTrailingSpaces(char *inputStr);
void splitIntoArgs(char *inputCommand, char *args[MAX_ARGS]);
int countArguments(char *args[]);
int customHasEqualSign(char *text);
void handleHashHelper(char *buffer, size_t *buffer_index);
void handleHash(char *text);
ssize_t _write(int fd, const void *buf, size_t count);
void listAlises(void);
int defineAlias(char *aliasName, char *aliasCmd);
int processAliasCmd(char *args[MAX_ARGS], int numArgs __attribute__((unused)));
void processUserInput(void);
void handleAliases(void);
int num_args(char *argv[]);
int alias_command(char *argv[], int numArgs);
void displayPrompt(void);
void processUserInput(void);
void processCommand(char *cmd);
int ex_code = 0;

#endif
