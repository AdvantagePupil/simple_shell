#include "shell.h"

/**
 * get_line - read command from stdin.
 *
 * Return: line read from stdin (Success)
 */
char *get_line(void)
{
char *line = NULL;
size_t length = 0;
ssize_t nchars_read;

if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);

nchars_read = getline(&line, &length, stdin);

/* If the return value of getline function is -1 we exit the shell */
if (nchars_read == -1)
{
free(line);
return (NULL);
}
return (line);
}
