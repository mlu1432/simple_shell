#include "main.h"
/**
 * _strcmp - Compares strings and returns 0 if true
 * @string1: String to be compared
 * @string2: String to be compared
 * Return: returns 0 if true
 */
int _strcmp(char *string1, char *string2)
{
int i;

for (i = 0; string1[i] != '\0'; i++)
;
for (i = 0; string2[i] != '\0'; i++)
{
if (string1[i] != string2[i])
{
return (string1[i] - string2[i]);
}
}
return (0);
}
