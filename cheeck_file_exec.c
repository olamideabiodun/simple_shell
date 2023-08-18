#include "shell.h"

/**
 * check_file_exec - checks is the path exists
 * @path: path of the file
 * @fileStat: stores info about the file if it it exists
 * Return: true for success, false otherwise
*/

bool check_file_exec(char *path, struct stat *fileStat)
{
int status;
status = stat(path, fileStat);
if (status == 0)
{
return (true);
}
return (false);
}

