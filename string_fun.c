#include "holberton.h"

void com_null(char* buf)
{
	free(buf);
	exit(EXIT_SUCCESS);
}

void exit_out(char *buf, char **com)
{
	free(buf);
	free_all(com);
	exit(EXIT_SUCCESS);
}

void env_out(char *buf, char **com, char **env)
{
	free(buf);
	free_all(com);
	print_env(env);
	exit(EXIT_SUCCESS);
}

void parent_free(char *buf, char **com)
{
  free(buf);
  free_all(com);
}

void _path(char **com, char *buf, char **env, char **argv, int conteo)
{
  struct stat statbuf_2;
  int i;
  char **dirs;

  i = 0;
  dirs = store_environ(com[0], env);
  for (; dirs[i]; ++i)
    {
      if (stat(dirs[i], &statbuf_2) == 0)
	execve(dirs[i], com, NULL);
    }
  error_msg(argv, com[0], conteo);
  free(buf);
  free_all(com);
  free_all(dirs);
  exit(EXIT_SUCCESS);
}

