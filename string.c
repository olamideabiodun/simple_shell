#include "shell.h"

/**
 * _strcpy - copies one string to another
 * @des: destination
 * @src: source
 * @des_len: destination size
 */
void _strcpy(char *des, const char *src, size_t des_len)
{
	size_t i = 0;

	while (*src != '\0' && i < des_len -1)
	{
		*des = *src;
		des++;
		src++;
		i++;
	}
	*des = '\0';
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

/**
 * _strdup - duplicates a string
 * @src: string to duplicate
 *
 * Return: duplicated string
 */
char *_strdup(const char *src)
{
	size_t len;
	char *des;

	if (src == NULL)
		return (NULL);

	len = _strlen(src) + 1;
	des = (char *)malloc(len);

	if (des != NULL)
	{
		_strcpy(des, src, 100);
	}
	return (des);
}

/**
 * _strncmp - compares n number of chars between two strings
 * @s1: string 1
 * @s2: string 2
 * @n: characters count 
 * Return: 0 for equal, !0 otherwise
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
    for (;n > 0 && *s1 && (*s1 == *s2); n--, s1++, s2++)
        ;
    if (n == 0)
    return (0);

    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

/**
 * _strcmp - compares two strings
 * @str1: string 1
 * @str2: string 2
 * Return: 0 for success
 */
int _strcmp(const char *str1, const char *str2)
{
        while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2)
            return (*str1 - *str2);
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

/**
 * _atoi- conveerts a string to an integer
 * @s: the string to be converted
 * Return: Success;
*/
int _atoi(char *s)
{
int al = 1;
int x = 0;
unsigned int sum = 0;
/*check the sign of the number...*/
while (s[x] != '\0' && !(s[x] <= 57 && s[x] >= 48))
{
if (s[x] == 45)
al *= -1;
x++;
}
while (s[x] <= 57 && (s[x] >= 48 && s[x] != '\0'))
{
sum = (sum * 10) + (s[x] - '0');
x++;
}
sum *= al;
return (sum);
}

/**
 * free_string - frees an array of strings (vector)
 * @vector: vector.
 * @count: number of words in the vector.
*/

void free_string(char **vector, size_t count)
{
    size_t i = 0;
    for (; i < count; ++i)
        free(vector[i]);
    free(vector);
}
