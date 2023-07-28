#include "main.h"
/**
 * _strcmp - Compares two strings
 * @string1: String to be compared
 * @string2: String to be compared
 * Return: 0 if are the same, > 0 if str1 is greater, < 0 if str2 is greater
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
