#include "shell.h"

void exitErr(char *prgm, int c_count, char *msg, char *err, char *arg1)
{
  char *c_count_str = intTOstr(c_count);
  write(STDERR_FILENO, prgm, _strlen(prgm));
  write(STDERR_FILENO, ": ", 2);
  write(STDERR_FILENO, c_count_str, _strlen(c_count_str));
  write(STDERR_FILENO, ": ", 2);
  write(STDERR_FILENO, msg, _strlen(msg));
  write(STDERR_FILENO, ": ", 2);
  write(STDERR_FILENO, err, _strlen(err));
  write(STDERR_FILENO, ": ", 2);
  write(STDERR_FILENO, arg1,  _strlen(arg1));
  write(STDERR_FILENO, "\n", 1);
}
