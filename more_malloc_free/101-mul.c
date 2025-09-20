#include "main.h"
#include <stdlib.h>

/**
 * _isdigit - checks if character is a digit
 * @c: character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: string to check
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * print_error - prints Error and exits
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
 * validate_args - validates arguments
 * @argc: argument count
 * @argv: argument vector
 */
void validate_args(int argc, char **argv)
{
	int i, j;

	if (argc != 3)
		print_error();

	for (i = 1; i < 3; i++)
	{
		if (argv[i] == NULL || argv[i][0] == '\0')
			print_error();
		for (j = 0; argv[i][j]; j++)
		{
			if (!_isdigit(argv[i][j]))
				print_error();
		}
	}
}

/**
 * multiply - multiplies two number strings
 * @num1: first number
 * @num2: second number
 */
void multiply(char *num1, char *num2)
{
	int len1, len2, len, i, j, n1, n2, sum;
	int *result;

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	len = len1 + len2;

	result = malloc(sizeof(int) * len);
	if (result == NULL)
		exit(98);

	for (i = 0; i < len; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			n1 = num1[i] - '0';
			n2 = num2[j] - '0';
			sum = n1 * n2 + result[i + j + 1];
			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}

	i = 0;
	while (i < len && result[i] == 0)
		i++;

	if (i == len)
		_putchar('0');
	else
		while (i < len)
			_putchar(result[i++] + '0');

	_putchar('\n');
	free(result);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	validate_args(argc, argv);
	multiply(argv[1], argv[2]);
	return (0);
}
