#include "shell.h"

/**
 * _myhistory - this function will display the history list,
 * every command in a line, and adding the line numbers at the end,
 * starting at 0.
 * @info: the structure that contain the potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: will always return 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - will set the alias to a string
 * @info: the parameter structure
 * @str: string alias
 *
 * Return: if succeded will always return 0, if not will return 1
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - will set an alias to a string
 * @info: the parameter structure
 * @str: string alias
 *
 * Return: if succeded will always return 0, if not it will return 1
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - will print THE alias string
 * @node: the alias node
 *
 * Return: on success returns 0 and on error returns 1
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - copy the alias builtin
 * @info: the structure that  contain the potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: will  Always return 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
