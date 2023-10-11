#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>
#define BUFFER_SIZE 1024

int main(void);
char *customGetLine(void);
char *customStrtok(char *str, const char *delim);
void *custom_realloc(void *ptr, size_t size);
void *custom_memcpy(void *dst, const void *src, size_t n);
int customStringCopy(char *destination, const char *source, int size);
int customStringLength(const char *str);
int customStringCompare(const char *strA, const char *strB);

#endif
