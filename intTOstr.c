#include "shell.h"

char *intTOstr(unsigned int n)
{
    char *s;
    int len = 0, k;
    unsigned int n_c = n;
    while (n_c > 0)
    {
        n_c /= 10;
        len++;
    }
    n_c = n;
    k = len - 1;
    s = malloc(sizeof(char) * (len + 1));
    if (s == NULL)
      {
        return (NULL);
      }
    if (n_c == 0)
    {
        s[0] = '0';
        s[1] = '\0';
        return (s);
    }
    while (k >= 0)
    {
        s[k] = '0' + (n_c % 10);
        n_c /= 10;
        k--;
    }
    s[len] = '\0';
    return (s);
}
