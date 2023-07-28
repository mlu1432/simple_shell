#include "main.h"
/**
 * _strdup - returns a string duplicated
 * @string: string to be duplicated
 * Return: returns the duplicated string pointer
 */
char *_strdup(char *string)
{
unsigned int i, length;
char *str_dup;

if (string == NULL)
return (NULL);

for (length = 0; string[length] != '\0'; length++)
;
str_dup = (char *) malloc(sizeof(char) * (length + 1));
if (str_dup == NULL)
return (NULL);
for (i = 0; i <= length; i++)
{
str_dup[i] = string[i];
}
return (str_dup);
}
