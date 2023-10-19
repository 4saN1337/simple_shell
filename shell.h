#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define DELIMTR " \t\n"
extern char **environ;

char *getting_line(void);
char **tokenizer(char *line);
int _executing(char **command, char **argv, int indx);
char *_getenv(char *avariable);
char *_getpath(char *command);
void printerror(char *name, char *cmd, int indx);
void reverse_string(char *str, int len);
char *_itoa(int n);

char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

void freearrayofdstring(char **arr);


#endif
