#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stddef.h>
#include <signal.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define MAX_ARGS 1024

extern char **environ;
extern struct Node *myEnvironmentList;
static char *curCmd __attribute__((unused));
extern int ex_code;
/**
* struct Node - a custom data structure
* @str: a pointer to a character string
* @next: a pointer to the next node
*/
struct Node
{
	char *str;
	struct Node *next;
};

/**
* struct Alias - structure to represent an alias
* @name: the name of the alias
* @aliasCmd: the command associated with the the alias
*/
typedef struct Alias
{
	const char *name;
	const char *aliasCmd;
	struct Alias *next;
} Alias;

char *customGetLine(char **userInput, size_t *bufferSize, FILE *stream);
char *customStrtok(const char *str, const char *delim);
void *custom_realloc(void *ptr, size_t size);
void *custom_memcpy(void *dst, const void *src, size_t n);
int customStringCopy(char *destination, const char *source);
int customStringLength(const char *str);
int customStringCompare(const char *strA, const char *strB);
char *customGetEnv(const char *name);
char *custom_strdup(char *input_str);
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
int defineAlias(char *aliasName, const char *aliasCmd);
int processAliasCmd(char *args[MAX_ARGS], int numArgs __attribute__((unused)));
void processUserInput(void);
void handleAliases(void);
int num_args(char *argv[]);
int alias_command(char *argv[], int numArgs);
void displayPrompt(void);
void processUserInput(void);
void processCommand(char *cmd);
/** add_node(struct Node **head, struct Node *newNode);*/
void remEnvVar(struct Node **head, const char *name);
void setEnvVar(struct Node **head, const char *name, const char *value);
void updateEnviron(struct Node *head);
void changeDirectory(char *newPath);
int customSetEnv(const char *name, const char *vaue, int overwrite);
char *customFindChar(const char *source, int target);
int customExit(char *status, int cmdCount, char *shellName, char **cmdArgs);
void DisplayAllAliases(Alias *aliases);
int customcheck(char **cmd_args, char *curCmd, char *error, int i, char **env);
int _putchar(char character);
void printEnvironment(struct Node *head);
void freeEnvironmentList(struct Node *head);
int dispayEnvironment(void);
int setEnvironmentVariable(const char *name, const char *value);
int unsetEnvironmentVariable(const char *name);
void executeCommand(char **args, char *argv, int i);
void executeWithExecve(char *command, char **p, char **env);
void printError(char *error, int i, char *command);
void printString(char *str);
void printNumber(int n);
void handleSegmentationFault(int signalNumber);
int procShellCmd(char **arguments);
void printShellErr(char *shellName, int cmdCount, char *cmdName, char *cmdArg);
void handleSegfault(int signo);
int main(int argCnt, char **argVct);
void handleInterrupt(int signo);
char *readUserCommand(void);
int isWhiteSpace(char character);
void removeWhiteSpaces(char *text);
char *readInputLine(void);
int exitShell(char *argument);
int customAtoi(char *str);
int customIsNumber(const char *str);
void ifEmpty(struct Node **head, char *newEnvVar, size_t newVarLength);
void customStrTok(char *command, char *argv[MAX_ARGS]);
static struct Node *new_node(char *str) __attribute__((unused));
static struct Node *new_node(char *str)
{
	struct Node *node = malloc(sizeof(struct Node));

	if (node == NULL)
		return (NULL);
	node->str = str;
	node->next = NULL;
	return (node);
}
static void add_node(struct Node **head, struct Node *node) __attribute__((unused));
static void add_node(struct Node **head, struct Node *node)
{
	if (*head == NULL)
		*head = node;
	else
	{
		struct Node *current = *head;
		for (; current->next != NULL ; )
			current = current->next;
		current->next = node;
	}
}
int displayEnvironment(void);

#endif
