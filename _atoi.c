#include "shell.h"
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
