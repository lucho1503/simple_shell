#include "holberton.h"

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

unsigned int _strlen_const(const char *name)
{
  unsigned int i = 0;

  while (name[i])
    ++i;
  return (i);
}

unsigned int _strlen(char *s)
{
  unsigned int i = 0;
  while (s[i] != '\0')
    ++i;
  return (i);
}

char *_strncpy(char *dest, char *src, int n)
{
  int i = 0;
  for (; src[i] != '\0' && i < n; i++)
    dest[i] = src[i];
  for (; i < n; i++)
    dest[i] = '\0';
  return (dest);
}

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
