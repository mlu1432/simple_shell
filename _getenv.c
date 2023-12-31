#include "main.h"
/**
 * _getenv - buffer content of a string
 * @buffer: buffer to recieve the environment variable
 * Return: the variable
 */
char *_getenv(char *buffer)
{
int i = 0;
char *delim = "=";
char *env_token, *envcopy, *env_token_dup;

if (buffer != NULL)
{
if (environ == NULL)
return (NULL);
envcopy = _strdup(environ[i]);
while (envcopy != NULL)
{
env_token = _strtok(envcopy, delim);
if (_strcmp(env_token, buffer) == 0)
{
env_token = _strtok(NULL, delim);

env_token_dup = _strdup(env_token);
free(envcopy);
return (env_token_dup);
}
i++;
free(envcopy);
envcopy = _strdup(environ[i]);
}
}
return (NULL);
}
