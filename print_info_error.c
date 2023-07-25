#include "shell.h"

/**
 * _erratoi - string convertes into a an integer
 * @s: string to be converted
 * Return: in case of no numbers in the string, return 0; otherwise,
 *       return a converted number -1 on error
 */
int _erratoi(char *s)
{
	int index = 0;
	unsigned long int convertedNumber = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (index = 0;  s[index] != '\0'; index++)
	{
		if (s[index] >= '0' && s[index] <= '9')
		{
			convertedNumber *= 10;
			convertedNumber += (s[index] - '0');
			if (convertedNumber > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (convertedNumber);
}

/**
 * print_error - prints an error message
 * @info: return info struct and the parameter
 * @estr: contains the specified error type in a string
 * Return: in case of no numbers in the string, return 0; otherwise
 *        return a converted number -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - the decimal (integer) number is printed (base 10) by the function
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: amount of characters printed
 */
int print_d(int input, int fd)
{
	int (*print_char)(char) = _putchar;
	int loop_i, count = 0;
	unsigned int absolute_v, current_d;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		absolute_v = -input;
		__putchar('-');
		count++;
	}
	else
		absolute_v = input;
	current_d = absolute_v;
	for (loop_i = 1000000000; loop_i > 1; loop_i /= 10)
	{
		if (absolute_v / loop_i)
		{
			__putchar('0' + current_d / loop_i);
			count++;
		}
		current %= loop_i;
	}
	__putchar('0' + current_d);
	count++;

	return (count);
}

/**
 * convert_number - itoa clone, converter function
 * @num: the number
 * @base: the base
 * @flags: an argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static bufferstring[50];
	char signFlag = 0;
	char *pointer;
	unsigned long absoluteValue = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		absoluteValue = -num;
		signFlag = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pointer = &buffer[49];
	*pointer = '\0';

	do	{
		*--pointer = array[absoluteValue % base];
		absoluteValue /= base;
	} while (absoluteValue != 0);

	if (signFlag)
		*--pointer = signFlag;
	return (pointer);
}

/**
 * remove_comments - First, '#' is replaced with '/0'
 * @buf: Modify the address of the string
 *
 * Return: 0 always;
 */
void remove_comments(char *buf)
{
	int index;

	for (index = 0; buf[index] != '\0'; index++)
		if (buffer[index] == '#' && (!index || buffer[index - 1] == ' '))
		{
			buffer[index] = '\0';
			break;
		}
}
