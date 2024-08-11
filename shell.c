#include "shell.h"

/**
 * main - main function for the simple shell.
 *
 *@argc: number of arguments.
 *@argv: arguments.
 * Return:  (Success)
 */
int main(int argc, char **argv)
{
char *line = NULL;
char **command = NULL;
int status = 0;
int number = 0;
(void) argc;

/* infinite loop unless we exit the SHELL's prompt */
while (1)
{
line = get_line();

/* If the getline function failed or reached EOF or used ctrl + D */
if (line == NULL)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
return (status);
}
number++;

/* Now we do tokenization or parsing. We split the string line into an array */
command = parsing(line);
if (command == NULL)
continue;

/* Now we execute the commands the user types */
if (is_built_in(command[0]) == 1)
handling_exit_env(command, argv, status, number);
else
status = execute_command(command, argv, number);
}
}
