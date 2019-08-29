#include "holberton.h"

/**
 * _puterror - write standard error
 * @c: the caracter
 * Return: write
 */

int _puterror(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

/**
 * error_msg - print an error message
 * @argv: argv
 * @com: com
 * @i: i
 */

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
	write(STDERR_FILENO, " : ", 2);
	write(STDERR_FILENO, com, _strlen(com));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
 * _eof - check end of line
 * @buf: first integer
 * Return: alwais zero
 */

void _eof(char *buf)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buf);
	exit(0);
}

/**
 * error_fork - check the fork: if it is -1 print the error
 * Return: exit failure
 */

void error_fork(void)
{
	perror("Error:");
	exit(EXIT_FAILURE);
}
