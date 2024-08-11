#include "shell.h"

/**
 * _getenv - gets the value of the global variable
 * @name: name of the global variable
 * Return: string of value
 */
char *_getenv(const char *name)
{
char *env;
char *cpy_name;
unsigned int i = 0;
unsigned int length;

length = _conststrlen(name);
cpy_name = malloc((sizeof(char) * length) +1);
if (!cpy_name)
return (NULL);

_strncpy(cpy_name, name, length);

env = strtok(environ[i], "=");
while (environ[i])
{
if (_strcmp(env, cpy_name))
{
env = strtok(NULL, "\n");
free(cpy_name);
return (env);
}
++i;
env = strtok(environ[i], "=");
}
free(cpy_name);
return (NULL);
}

/**
 * get_path - handles the path.
 *
 *@command: command from stdin.
 * Return: address of pointer (Success)
 */
char *get_path(char *command)
{
char *env_path = NULL, *path_check = NULL, *dir;
int i;
struct stat st;

for (i = 0; command[i]; i++)
{
if (command[i] == '/')
{
if (stat(command, &st) == 0)
return (_strdup(command));
return (NULL);
}
}
env_path = _getenv("PATH");
if (!env_path)
return (NULL);

dir = strtok(env_path, ":");
while (dir != NULL)
{
path_check = malloc(_strlen(dir) + _strlen(command) + 2);
if (path_check != NULL)
{
_strcpy(path_check, dir);
_strcat(path_check, "/");
_strcat(path_check, command);
if (stat(path_check, &st) == 0)
{
free(env_path);
return (path_check);
}

free(path_check), path_check = NULL;
dir = strtok(NULL, ":");
}
}
return (NULL);
}
