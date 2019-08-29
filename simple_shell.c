#include "holberton.h"

/**
 * INThandler - handle the signals.
 * @s: signal of input.
 * Return: nothing.
 */

void INThandler(int s)
{
	(void)s;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * main - entry point.
 * @argc: count arguments.
 * @argv: vector of args.
 * @env: variable of environ.
 * Return: 0 if is succesfull 1 else.
 */

int main(int argc, char **argv, char **env)
{
  char *buf;char **com;
  size_t len; ssize_t ch;
  char *env_com = "env", *pesos = "$ ", *exit_com = "exit";
  pid_t hijo; struct stat statbuf;	
  int status, i;
  (void)argc;

  buf = NULL, len = 0, i = 0;
  /* print standard input */
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, pesos, 2);
	/* ctrl + c */
	signal(SIGINT, INThandler);
	/* loop infinite */
	while ((ch = getline(&buf, &len, stdin)))
	{
	  /* end of file */
		if (ch == EOF)		
			_eof(buf);
		++i;
		com = _strtok(buf);
		hijo = fork();
		if (hijo == -1)
			error_fork();
		if (hijo == 0)
		{
		        if (com == NULL)
				com_null(buf);
			else if (_strcmp(exit_com, com[0]))
				exit_out(buf, com);
			else if (_strcmp(env_com, com[0]))
				env_out(buf, com, env);
			else if (stat(com[0], &statbuf) == 0)
				execve(com[0], com, NULL);
			else
				_path(com, buf, env, argv, i);
		}
		else
		{
			wait(&status);
			if (com == NULL)
				parent_free(buf, com);
			else if (_strcmp(exit_com, com[0]))
				exit_out(buf, com);
			else
				parent_free(buf,com);
		}
		len = 0; buf = NULL;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, pesos, 2);
	}
	if (ch == -1)
	  {
	    return (EXIT_FAILURE);
	  }
	return (EXIT_SUCCESS);
}
