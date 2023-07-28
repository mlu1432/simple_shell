#include "main.h"
/**
 * _strcmp - Compares two strings
 * @string1: String to be compared
 * @string2: String to be compared
 * Return: 0 if are the same, > 0 if str1 is greater, < 0 if str2 is greater
 */
int _strcmp(char *string1, char *string2)
{
	int a;

	for (a = 0; string1[a] != '\0'; a++)
		;
	for (a = 0; string2[a] != '\0'; a++)
	{
		if (string1[a] != string2[a])
		{
			return (string1[a] - string2[a]);
		}
	}
	return (0);
}
