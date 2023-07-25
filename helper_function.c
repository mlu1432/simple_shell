#include "shell.h"

/**
 * _strlen - the length of a string returns
 * @s: checking the length of a string
 *
 * Return: string length as an integer
 */
int _strlen(char *s)
{
	int index = 0;

	if (!s)
		return (0);

	while (*s++)
		index++;
	return (index);
}

/**
 * _strcmp - compares two strings lexicographically.
 * @s1: first strang
 * @s2: second strang
 *
 * Return: negative if s1 s2, positive if s1 > s2, and zero if s1 == s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks whether needle starts with haystack
 * @haystack: string to search
 * @needle: substring to find
 *
 * Return: NULL or address of next char in haystack
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - it on concatenates two strings
 * @dest: a destination buffer
 * @src: a source buffer
 *
 * Return: destination buffer pointer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
