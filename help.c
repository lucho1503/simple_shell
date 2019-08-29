#include "holberton.h"

/**
 * _strcmp - compare two string
 * @s1: char
 * @s2: char
 * Return: z
 */

int _strcmp(char *s1, char *s2)
{
	unsigned int z = 0;

	while (s1[z])
	{
		if (s1[z] != s2[z])
			return (0);
		++z;
	}
	return (z);
}

/**
 * _strlen_const - count the large of variable
 * @name: char
 * Return: i count caracteres
 */

unsigned int _strlen_const(const char *name)
{
	unsigned int i = 0;

	while (name[i])
		++i;
	return (i);
}

/**
 * _strlen - count the string
 * @s: char
 * Return: i
 */

unsigned int _strlen(char *s)
{
	unsigned int i = 0;

	while (s[i] != '\0')
		++i;
	return (i);
}

/**
 * _strncpy - copy the string
 * @dest: char
 * @src: char
 * @n: int
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	for (; src[i] != '\0' && i < n; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';
	return (dest);
}

/**
 * _strncpyconst - copy the caracteres
 * @dest: char
 * @src: char
 * @n: int
 * Return: dest
*/

char *_strncpyconst(char *dest, const char *src, int n)
{
	int i = 0;

	while (i < n && *src != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
