#include "main.h"
/**
 * _getenv - Get the content of a global variable
 * @global_var: Variable to extract from environ
 * Return: Pointer to the content of a variable, or NULL if fails
 */
char *_getenv(char *global_var)
{
	int i = 0;
	const char cutter[] = "=";
	char *env_token, *envcopy, *env_tok_dup;

	if (global_var != NULL)
	{
		if (environ == NULL)
			return (NULL);
		envcopy = _strdup(environ[i]);
		while (envcopy != NULL)
		{
			env_token = strtok(envcopy, cutter);
			if (_strcmp(env_token, global_var) == 0)
			{
				env_token = strtok(NULL, cutter);

				env_tok_dup = _strdup(env_token);
				free(envcopy);
				return (env_tok_dup);
			}
			i++;
			free(envcopy);
			envcopy = _strdup(environ[i]);
		}
	}
	return (NULL);
}
