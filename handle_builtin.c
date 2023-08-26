
#include "shell.h"

/**
 * builtIn - handles built-n commands
 * @input: command
 * @env: env
 * @user_input: user input
 * @exitStat: exit Status
 * @c_count: command count
 */
void builtIn(char **input, char **envp, char *user_input, int *exitStat, unsigned int c_count)
{
  int i = 0;
  bool shouldPrintEnv = false;
  int ex = 0;

  if (_strcmp(input[0], "env") == 0 || _strcmp(input[0], "printenv") == 0)
    {
      shouldPrintEnv = true;
    }

  if (_strcmp(input[0], "exit") == 0)
    {

      if(input[1])
	{
	  ex = _atoi(input[1]);
	  if(_strcmp(input[1], "HBTN") == 0)
	    {
	      exitErr("./hsh", c_count, input[0],"Illegal number", input[1]);
	      ex = 2;
	    }
	  
	  else if(ex < 0)
	    {
	      exitErr("./hsh", c_count, input[0], "Illegal number", input[1]);
	      ex = 2;
	    }
	  *exitStat = ex;
	}
     
      free(user_input);
      free_string(input);
      if (shouldPrintEnv)
        {
	  for (; envp[i] != NULL; i++) {
	    write(STDOUT_FILENO, envp[i], _strlen(envp[i]));
	    write(STDOUT_FILENO, "\n", 1);
	  }
        }
      exit(*exitStat);
    }
}
