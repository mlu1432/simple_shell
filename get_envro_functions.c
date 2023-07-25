#include "shell.h"

/**
 * get_environ - our environment is returned as a string array
 * @info: contains potential arguments. Used to maintain structure
 *          constant function prototype.
 * Return: Always 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - an environment variable is removed
 * @info: Contains potential arguments used to maintain
 *	 the function prototypes.
 *  Return: if deleted, 1; otherwise, 0
 * @var: string env var property
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t num = 0;
	char *pointer;

	if (!node || !var)
		return (0);

	while (node)
	{
		pointer = starts_with(node->str, var);
		if (pointer && *pointer == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), num);
			num = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		num++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: 0 always successful
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buffer = NULL;
	list_t *node;
	char *pointer;

	if (!var || !value)
		return (0);

	buffer = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buffer)
		return (1);
	_strcpy(buffer, var);
	_strcat(buffer, "=");
	_strcat(buffer, value);
	node = info->env;
	while (node)
	{
		pointer = starts_with(node->str, var);
		if (pointer && *pointer == '=')
		{
			free(node->str);
			node->str = buffer;
			info->env_changed = 1;
			return (1);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buffer, 0);
	free(buffer);
	info->env_changed = 1;
	return (1);
}
