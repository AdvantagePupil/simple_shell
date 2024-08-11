#include "shell.h"

/**
 * reverse - reverses a string.
 *
 *@str: string.
 *@length: string length.
 * Return: no return (Success)
 */
void reverse(char str[], int length)
{
int start = 0;
int end = length - 1;
while (start < end)
{
char temp = str[start];
str[start] = str[end];
str[end] = temp;
end--;
start++;
}
}

/**
 * _itoa - converts an integer into a null-terminated string.
 *
 *@n: integer we will convert.
 * Return: string converted from int (Success)
 */
char *_itoa(int n)
{
char buffer[20];
int i = 0;

if (n == 0)
buffer[i++] = '0';
else
{
while (n > 0)
{
buffer[i++] = (n % 10) + '0';
n /= 10;
}
}
buffer[i] = '\0';
reverse(buffer, i);
return (_strdup(buffer));
}

/**
 * error_msg - writes hsh error messages.
 *
 *@name: name of shell.
 *@command: command from stdin.
 *@number: number of times the prompt is used.
 * Return: no return (Success)
 */
void error_msg(char *name, char *command, int number)
{
char *int_asc;
int_asc = _itoa(number);

write(STDERR_FILENO, name, _strlen(name));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, int_asc, _strlen(int_asc));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, command, _strlen(command));
write(STDERR_FILENO, ": not found\n", 12);

free(int_asc);
}
