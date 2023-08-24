#include "shell.h"

/**
 * check_file_exec - checks if the file exists
 * @file: path of the file
 * @fileStat: stores info about the file if it exists
 * Return: true for success, false otherwise
*/

bool check_file_exec(char *file, struct stat *fileStat, int *valid_cmd)
{
  int status;
  status = stat(file, fileStat);
  if (status == 0)
    {
      *valid_cmd = 1;
      return (true);
    }
  *valid_cmd = 0;
  return (false);
}
/**
 * check_file_in_path - checks if the file exists in Path
 * @filename: filename
 * @fileStat: stores info about the file if it exists
 * @path: path
 * Return: file path
 */
char *check_file_in_path(char *filename, struct stat *fileStat, char *path, int *valid_cmd)
{

char *full_path;
char *token_copy = _strdup(path);
char *token = strtok(token_copy, ":");

while (token != NULL)
  {
    full_path = _strcat(3, token, "/", filename);
    if (check_file_exec(full_path, fileStat, valid_cmd))
      {
	free(token_copy);
	return (full_path);
      }
    free(full_path);
    token = strtok(NULL, ":");
   }
 free(token_copy);
 return (NULL);
}
/**
 * _execve - executes a file
 * @path: path of the file
 * @commands: commands
 * @envp: envp
 * Return: true for success, false otherwise
 */
int _execve(char *path, char **commands, char **envp, int *exitStat)
{
  
  pid_t child_process;
  int status;

  child_process = fork();
  if (child_process == -1)
    {
      perror("Error: Fork");
      exit(errno);
    }
  if (child_process == 0)
    if (execve(path, commands, envp) == -1)
      {
	
	*exitStat = 2;
      exit(*exitStat);
      }
  
  if (waitpid(child_process, &status, 0) == -1)
    {
      perror("Error: Fork");
      exit(errno);
    }
  if (WIFEXITED(status))
    *exitStat = WEXITSTATUS(status);
  errno = *exitStat;

  return (0);
}
