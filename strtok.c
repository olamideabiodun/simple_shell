#include "shell.h"

char *strtok_custom(char *str, const char *delim) {
    size_t i = 0;
    static char *start = NULL;
    char *token_start = start;
    char *token_end = start;
    if (str != NULL)
        start = str;
    else if (start == NULL)
        return NULL;


    while (*token_end != '\0') {
        bool is_delim = false;
        for (; delim[i] != '\0'; i++) {
            if (*token_end == delim[i]) {
                *token_end = '\0';
                is_delim = true;
                break;
            }
        }
        if (is_delim) {
            start = token_end + 1;
            if (token_start != token_end)
                return token_start;
            else
                token_start = start;
        }
        token_end++;
    }

    start = NULL;
    if (token_start == token_end)
        return NULL;

    return token_start;
}
