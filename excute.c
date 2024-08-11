#include "shell.h"

/**
 * execute_command - executes command read from stdin.
 *
 *@command: command.
 *@argv: contains arguments
 *@number: number of times the prompt is used.
 * Return: exit status (Success)
 */
int execute_command(char **command, char **argv, int number)
{
char *temp = NULL;
pid_t pid;
int status = 0;

temp = get_path(command[0]);
if (!temp)
{
error_msg(argv[0], command[0], number);
free_memory(command);
return (127);
}
pid = fork();

if (pid == -1)
{
perror("Error:");
exit(EXIT_FAILURE);
}
if (pid == 0)
{
if (execve(temp, command, environ) == -1)
{
perror(argv[0]);
free(temp), temp = NULL;
free_memory(command);
exit(EXIT_FAILURE);
}
}
else
{
waitpid(pid, &status, 0);
free_memory(command);
free(temp), temp = NULL;
}
return (WEXITSTATUS(status));
}
