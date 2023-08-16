#include "shell.h"

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
