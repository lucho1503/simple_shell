#include "holberton.h"

/**
 * count_dir - count the files in the path
 * @path: path
 * Return: dir
 */

unsigned int count_dir(char *path)
{
	unsigned int dir = 0, count = 0, flag = 0;

	for (; path[count]; ++count)
	{
		if (path[count] != ':')
			flag = 1;
		if ((flag && path[count + 1] == ':') || (flag && path[count + 1] == '\0'))
		{
			++dir;
			flag = 0;
		}
	}
	return (dir);
}

/**
 * _strncpycmd - entry point
 * @dest: dest
 * @src: src
 * @com: com
 * @n: n
 * @c: c
 * Return: dest
 */

char *_strncpycmd(char *dest, char *src, char *com, int n, int c)
{
	int i, j;

	i = 0, j = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '/';
	i++;

	while (j < c && com[j] != '\0')
	{
		dest[i] = com[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * store_environ - entry point
 * @com: com
 * @environ: enviaron
 * Return: dris
 */

char **store_environ(char *com, char **environ)
{
	char **dirs;
	char *path, *dir;
	unsigned int largo, count;
	int dir_len, len_com;

	path = _getenv("PATH", environ);
	largo = count_dir(path);
	dirs = malloc(sizeof(char *) * (largo + 1));
	if (dirs == NULL)
		return (NULL);
	dir = strtok(path, ":");
	for (count = 0; dir != NULL; ++count)
	{
		dir_len = _strlen(dir);
		len_com = _strlen(com);
		dirs[count] = malloc(sizeof(char) * (dir_len + len_com + 2));
		if (dirs[count] == NULL)
		{
			free_all(dirs);
			return (NULL);
		}
		_strncpycmd(dirs[count], dir, com, dir_len, len_com);
		dir = strtok(NULL, ":");
	}
	dirs[count] = NULL;
	return (dirs);
}

/**
 * _getenv - entry point
 * @name: name
 * @environ: enviaron
 * Return: NULL
 */

char *_getenv(const char *name, char **environ)
{
	char *value;
	char *copy;
	unsigned int i, len;

	len = _strlen_const(name);
	copy = malloc((sizeof(char) * len) + 1);
	if (copy == NULL)
		return (NULL);
	_strncpyconst(copy, name, len);
	i = 0;
	value = strtok(environ[i], "=");
	while (environ[i])
	{
		if (_strcmp(value, copy))
		{
			value = strtok(NULL, "\n");
			free(copy);
			return (value);
		}
		++i;
		value = strtok(environ[i], "=");
	}
	free(copy);
	return (NULL);
}

/**
 * print_env - print enviaron variables
 * @environ: environ
 */

void print_env(char **environ)
{
	int count, len;

	for (count = 0; environ[count]; ++count)
	{
		len = _strlen(environ[count]);
		write(STDOUT_FILENO, environ[count], len);
		write(STDOUT_FILENO, "\n", 1);
	}
}
