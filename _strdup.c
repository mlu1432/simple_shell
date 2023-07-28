#include "main.h"
/**
 * _strdup - Duplicates a string
 * @str: String to be duplicated
 * Return: Pointer to the duplicated string
 */
char *_strdup(char *string)
{
	unsigned int i, len;
	char *str_dup;

	if (string == NULL)
		return (NULL);

	for (len = 0; string[len] != '\0'; len++)
		;
	str_dup = (char *) malloc(sizeof(char) * (len + 1));
	if (str_dup == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
	{
		str_dup[i] = string[i];
	}
	return (str_dup);
}
