#include "main.h"
#include <stdlib.h>

/**
 * print_error - prints Error and exits with status 98
 */
void print_error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * _strlen - returns length of string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * is_digit - checks if string contains only digits
 * @s: string to check
 * Return: 1 if all digits, 0 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	if (!s[0])
		return (0);

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * print_number - prints number from result array
 * @result: array containing digits
 * @size: size of array
 */
void print_number(int *result, int size)
{
	int i = 0;

	/* Skip leading zeros */
	while (i < size && result[i] == 0)
		i++;

	/* If all zeros, print 0 */
	if (i == size)
		_putchar('0');
	else
	{
		while (i < size)
		{
			_putchar(result[i] + '0');
			i++;
		}
	}
	_putchar('\n');
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int len1, len2, len_result, i, j, carry, n1, n2, sum;
	int *result;

	/* Check argument count */
	if (argc != 3)
		print_error();

	/* Validate input strings */
	if (!is_digit(argv[1]) || !is_digit(argv[2]))
		print_error();

	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);

	/* Handle zero cases */
	if ((len1 == 1 && argv[1][0] == '0') ||
		(len2 == 1 && argv[2][0] == '0'))
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}

	len_result = len1 + len2;

	/* Allocate memory for result */
	result = malloc(sizeof(int) * len_result);
	if (result == NULL)
		print_error();

	/* Initialize result array */
	for (i = 0; i < len_result; i++)
		result[i] = 0;

	/* Multiply numbers using grade school algorithm */
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = argv[1][i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = argv[2][j] - '0';
			sum = n1 * n2 + result[i + j + 1] + carry;
			carry = sum / 10;
			result[i + j + 1] = sum % 10;
		}

		if (carry > 0)
			result[i + j + 1] += carry;
	}

	/* Print result */
	print_number(result, len_result);

	/* Free allocated memory */
	free(result);

	return (0);
}
