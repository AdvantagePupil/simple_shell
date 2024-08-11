#include "shell.h"

/**
 * parsing - splits the command read from stdin.
 *@line: line read from stdin.
 * Return:  split command(Success)
 * or NULL if failed.
 */
char **parsing(char *line)
{
char *token = NULL;
char *temp = NULL;
char **command = NULL;
int count = 0, i = 0;
if (line == NULL)
return (NULL);
temp = _strdup(line);
if (temp == NULL)
{
free(line);
return (NULL);
}
token = strtok(temp, " \t\n");
if (token == NULL)
{
free(line), line = NULL;
free(temp), temp = NULL;
return (NULL);
}
while (token)
{
count++;
token = strtok(NULL, " \t\n");
}
free(temp), temp = NULL;
command = malloc(sizeof(char *) * (count + 1));
if (!command)
{
free(line), line = NULL;
return (NULL);
}
token = strtok(line, " \t\n");
while (token)
{
command[i] = token;
token = strtok(NULL, " \t\n");
i++;
}
command[i] = NULL;
return (command);
}
