#include "shell.h"

/**
 * is_built_in - identifies built-in commands.
 *
 *@command: command
 * Return: 1 (command is built-in) (Success)
 * 0 (command is not built-in)
 */
int is_built_in(char *command)
{
char *table[] = {
"exit", "env", NULL
};
int i;

for (i = 0; table[i]; i++)
{
if (_strcmp(command, table[i]) == 0)
return (1);
}
return (0);
}

/**
 * handling_exit_env - handles exit and env
 *
 *@command: array
 *@argv: arguments
 *@status: status
 *@number: number of times promt is used
 * Return: no return (Success)
 */
void handling_exit_env(char **command, char **argv, int status, int number)
{
(void) argv;
(void) number;
if (_strcmp(command[0], "exit") == 0)
exit_sh(command, status);
if (_strcmp(command[0], "env") == 0)
_env(command);
}

/**
 * exit_sh - exits shell.
 *
 *@command: array
 *@status: status
 * Return: no return (Success)
 */
void exit_sh(char **command, int status)
{
free_memory(command);
exit(status);
}

/**
 * _env - prints environment variables
 *
 *@command: array
 * Return: no return (Success)
 */
void _env(char **command)
{
int i;
for (i = 0; environ[i]; i++)
{
write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
}
free_memory(command);
}
