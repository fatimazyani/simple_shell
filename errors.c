#include "shell.h"

/**
 *_eputs - will print the inputed string
 * @str: the given string to print
 *
 * Return: Null
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - will write the given character c into stderr
 * @c: The given character to be printed
 *
 * Return: wiil return 1 On success
 * Otherwise -1 is returned.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - will write the given character c into a given fd
 * @c: The given character to be printed
 * @fd: The given fd to be writed into
 *
 * Return: return 1 On success
 * Otherwise -1 is returned
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_putsfd - will print a given string
 * @str: the given string to print
 * @fd: the given fd to be writed into
 *
 * Return: return the number of character puted
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
