#include "shell.h"

/**
 * _strcpy - copies the string pointed to by src, including the
 *terminating null byte (\0), to the buffer pointed to by dest.
 *
 *@dest: pointer to a char.
 *@src: pointer to a char.
 * Return: pointer to dest (Success)
 */
char *_strcpy(char *dest, char *src)
{
int i;

for (i = 0; i < _strlen(src); i++)
{
*(dest + i) = *(src + i);
}

dest[i++] = '\0';
return (dest);
}

/**
 * _conststrlen - returns the length of a string.
 *
 *@s: string.
 * Return: length of a string (Success)
 */
int _conststrlen(const char *s)
{
int i = 0;
while (*s != '\0')
{
i++;
s++;
}
return (i);
}

/**
 * _strncpy - copies a string.
 *
 *@dest: pointer to a char.
 *@src: pointer to a char.
 *@n: integer.
 * Return: returns pointer to a char (Success)
 */
char *_strncpy(char *dest, const char *src, int n)
{
int i;
i = 0;

while (i < n && src[i] != '\0')
{
dest[i] = src[i];
i++;
}

while (i < n)
{
dest[i] = '\0';
i++;
}
return (dest);
}

/**
 * _strcmp - compares two strings.
 *
 *@s1: pointer to a char.
 *@s2: pointer to a char.
 * Return: returns an integer (Success)
 */
int _strcmp(char *s1, char *s2)
{
int i;

i = 0;

while (s1[i] != '\0' && s2[i] != '\0')
{
if (s1[i] != s2[i])
{
return (s1[i] - s2[i]);
}
i++;
}
return (0);
}
/**
 * _strcat - concatenates two strings.
 *
 *@dest: pointer to a char.
 *@src: pointer to a char.
 * Return: returns a pointer to a char (Success)
 */
char *_strcat(char *dest, char *src)
{
int i, j;

i = 0;
j = 0;

while (dest[i] != '\0')
{
i++;
}

while (src[j] != '\0')
{
dest[i] = src[j];
i++;
j++;
}
dest[i] = '\0';

return (dest);
}
