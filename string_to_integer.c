#include "shell.h"

/**
 * interactive - if shell is in interactive mode, it returns true
 * @info: the struct address
 *
 * Return: in interactive mode, 1; otherwise, 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - character is checked to see if it is a delimeter
 * @c: the character to check
 * @delim: the delimeter string
 * Return: 0 if is false and 1 if is true
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - verifies alphabetical characters
 * @c: character to input
 * Return: if c is alphabetical, 1; otherwise, 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - transform a string to an integer
 * @s: the string to be transformed
 * Return: 0 if string has no numbers, otherwise transformed number
 */

int _atoi(char *s)
{
	int index;
	int sign = 1;
	int flag = 0;
	int output;
	unsigned int result = 0;

	for (index = 0; s[index] != '\0' && flag != 2; index++)
	{
		if (s[index] == '-')
			sign *= -1;

		if (s[index] >= '0' && s[index] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[index] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
