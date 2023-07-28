#include "main.h"
/**
 * print_numbers - Prints numbers, used to print the error message
 * @num: number to print
 * Return: Number
 */

int print_numbers(int num)
{
	unsigned int number;
	int i = 0;

	if (num < 0)
	{
		number = -num;
		i = i + _putchar('-');
	}
	else
	{
		number = num;
	}
	if (number / 10 != '\0')
		i = i + print_numbers(number / 10);
	i = i + _putchar(number % 10 + '0');
	return (i);
}
