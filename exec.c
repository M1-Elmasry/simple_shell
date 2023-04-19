#include "main.h"

char *search_cmd(char *cmd)
{
  int i = 0;
  char *path, *s_paths, *s_paths2, *tok;
  char **tokens;
  struct stat s;

  if (!cmd)
    return (0);

  s_paths = getenv("PATH");
  s_paths2 = strdup(s_paths);
  tok = strtok(s_paths2, ":");
  tokens = extract_args(s_paths2, ":");

  while (tokens[i] != NULL)
  {
    path = calloc((strlen(tokens[i]) + strlen(cmd)) + 2, sizeof(char));

    if (!path)
    {
      perror("allocation failed");
      exit(EXIT_FAILURE);
    }

    strcpy(path, tokens[i]);
    strcat(path, "/");
    strcat(path, cmd);

    if (stat(path, &s) == 0)
    {
      if ((s.st_mode & EXEC) > 0)
      {
        free(s_paths2);
        return (path);
      }
      ++i;
    }
    ++i;
  }
  return (cmd);
}


int execute(char *cmd, char *args[], char *filename)
{
  pid_t pid;
  int status;

  if (!args)
    exit(EXIT_FAILURE);

  if (**args == 10)
  {
    return(0);
  }

  pid = fork();
  if (pid == 0) 
    {

      if (execve(cmd, args, NULL) == -1) 
      {
        perror(filename);
      }
      exit(EXIT_FAILURE);
    }

  else if (pid < 0) 
    {
    perror(filename);
  }

  else
  {
    do 
    {
      waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return (0);
}
