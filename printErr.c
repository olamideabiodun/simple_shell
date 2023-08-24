#include "shell.h"


void printerr(char *prgm, char *cmd_C, char *cmd, char *err)
{
write(STDERR_FILENO, prgm, _strlen(prgm));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, cmd_C, _strlen(cmd_C));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, cmd, _strlen(cmd));
write(STDERR_FILENO, err,  _strlen(err) );
write(STDERR_FILENO, "\n", 1);
}
