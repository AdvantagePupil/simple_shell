#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

char *get_line(void);
char **parsing(char *line);
int execute_command(char **command, char **argv, int number);
char *_getenv(const char *name);
void free_memory(char **array);
char *get_path(char *command);
void error_msg(char *name, char *command, int number);
char *_itoa(int n);
void reverse(char str[], int length);
void _env(char **command);
void exit_sh(char **command, int status);
void handling_exit_env(char **command, char **argv, int status, int number);
int is_built_in(char *command);

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _conststrlen(const char *s);
char *_strncpy(char *dest, const char *src, int n);
int _putchar(char c);
void _puts(char *str);

#endif
