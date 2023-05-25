#include "shell.h"

/**
 * bfree - will free a given pointer
 * @ptr: the address of the given pointer to free
 *
 * Return: if freed return 1, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
