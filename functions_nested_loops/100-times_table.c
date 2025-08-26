#include "main.h"

/**
 * print_number - prints a number with proper spacing
 * @num: number to print
 * @is_first: whether this is the first number in row
 */
void print_number(int num, int is_first)
{
	if (is_first)
	{
		_putchar('0');
	}
	else
	{
		_putchar(',');
		if (num < 10)
		{
			_putchar(' ');
			_putchar(' ');
			_putchar(' ');
		}
		else if (num < 100)
		{
			_putchar(' ');
			_putchar(' ');
		}
		else
		{
			_putchar(' ');
		}
		if (num >= 100)
			_putchar((num / 100) + '0');
		if (num >= 10)
			_putchar(((num / 10) % 10) + '0');
		_putchar((num % 10) + '0');
	}
}

/**
 * print_times_table - prints the n times table
 * @n: times table to print
 */
void print_times_table(int n)
{
	int row, col, result;

	if (n < 0 || n > 15)
		return;

	for (row = 0; row <= n; row++)
	{
		for (col = 0; col <= n; col++)
		{
			result = row * col;
			print_number(result, (col == 0));
		}
		_putchar('\n');
	}
}
