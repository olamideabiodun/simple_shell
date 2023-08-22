#include "shell.h"

/**
 * free_string - frees an array of strings (vector)
 * @vector: vector.
*/

void free_string(char **vector)
{
size_t i = 0;
for (; vector[i] != NULL; ++i)
free(vector[i]);
free(vector);
}

/**
 * _strlen - counts the length of string
 * @str: string to count
 *
 * Return: counts
 */
size_t _strlen(const char *str)
{
size_t len = 0;

while (*str != '\0')
{
len++;
str++;
}
return (len);
}
