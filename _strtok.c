#include "holberton.h"

/**
 * largo_del_comando - entry point.
 * @s: string.
 * Return: lenght of command.
 */

unsigned int largo_del_comando(char *s)
{
	unsigned int commands, i, flag;

	flag = 0;
	commands = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ')
			flag = 1;

		if ((flag && s[i + 1] == ' ') || (flag && s[i + 1] == '\0'))
		{
			++commands;
			flag = 0;
		}
		++i;
	}
	return (commands);
}

/**
 * _strtok - entry point.
 * @str: string recived.
 * Return: double pointer in tokens.
 */

char **_strtok(char *str)
{
	char **tk_hol;
	char *token;
	int i;
	unsigned int len;

	str[_strlen(str) - 1] = '\0';
	len = largo_del_comando(str);
	if (len == 0)
		return (NULL);
	tk_hol = malloc((sizeof(char *)) * (len + 1));
	if (tk_hol == NULL)
	{
		return (NULL);
	}
	i = 0;
	token = strtok(str, " ");
	while (token != NULL)
	{
		tk_hol[i] = malloc(_strlen(token) + 1);
		if (tk_hol[i] == NULL)
		{
			free_all(tk_hol);
			return (NULL);
		}
		_strncpy(tk_hol[i], token, _strlen(token) + 1);
		token = strtok(NULL, " ");
		++i;
	}
	tk_hol[i] = NULL;
	return (tk_hol);
}
