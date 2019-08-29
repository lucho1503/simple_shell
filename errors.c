#include "holberton.h"

int _puterror(char c)
{
        return(write(STDERR_FILENO, &c, 1));
}

void error_msg(char **argv, char *com, int i)
{
	int mul, len, copy;

	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	copy = i;
	mul = 1;
	len = 1;
	while (copy >= 10)
	{
		copy /= 10;
		mul *= 10;
		++len;
	}
	while (len > 1)
	{
		if ((i / mul) < 10)
		{
			_puterror((i / mul + '0'));
		}
		else
		{
			_puterror((i / mul) % 10 + '0');
		}
		--len;
		mul /= 10;
	}
	_puterror(i % 10 + '0');
      	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, com, _strlen(com));
	write(STDERR_FILENO, ": not found\n", 12);
}

void _eof(char *buf)
{
  if (isatty(STDIN_FILENO))
    write(STDOUT_FILENO, "\n", 1);
  free(buf);
  exit(0);
}


void error_fork(void)
{
  perror("Error:");
  exit(EXIT_FAILURE);
}

