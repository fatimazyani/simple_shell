#include "shell.h"

/**
 **_memset - will fill a given memory with a constant byte
 *@s: the given pointer
 *@b: the given byte to fill *s with
 *@n: the number of bytes to  fill
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - will free a string of strings
 * @pp: the given string of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - will move a block of memory
 * @ptr: the given pointer to the previous block of memory
 * @old_size: the size of the previous block of memory
 * @new_size: the size of the new block of memory
 *
 * Return: return pointer of the new location.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
