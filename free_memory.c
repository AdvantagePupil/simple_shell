#include "shell.h"

/**
 * free_memory - frees the memory allocated for an array.
 *
 *@array: array.
 * Return: no return (Success)
 */
void free_memory(char **array)
{
unsigned int i = 0;

/* if array is empty*/
if (array == NULL)
return;

while (array[i])
{
free(array[i]);
++i;
}

free(array);
}
