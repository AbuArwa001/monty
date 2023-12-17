#include "monty.h"
#include <ctype.h>
/**
 * power - finds the power
 * @base: base of power
 * @exponent: exponent to the base
 * Return: returns power of a number
*/
int power(int base, int exponent)
{
	int i = 0, num = 1;

	for (; i < exponent; i++)
	{
		num *= base;
	}

	return (num);
}
/**
 * _atoi - converts string to int
 * @str: string to be converted
 * Return: returns an integer
*/
unsigned int *_atoi(char *str)
{
	unsigned int res = 0, minus, *result;

	if (str == NULL)
	{
		return (NULL);
	}

	minus = *str == '-';

	if (minus)
	{
		str++;
	}

	while (*str)
	{
		if (!isdigit(*str))
		{
			return (NULL);
		}

		res = res * 10 + (*str++ - '0');
	}

	result = malloc(sizeof(int));

	if (result == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	*result = minus ? -res : res;
	return (result);
}
