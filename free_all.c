#include "holberton.h"

/**
 * free_all - free memory
 * @double_ptr: duuble
 */

void free_all(char **double_ptr)
{
	unsigned int i;

	i = 0;
	if (double_ptr == NULL)
		return;
	while (double_ptr[i])
	{
		free(double_ptr[i]);
		++i;
	}
	if (double_ptr[i] == NULL)
		free(double_ptr[i]);
	free(double_ptr);
}
