#include <stdio.h>

/**
 * print_large_fib - prints large fibonacci numbers using split arithmetic
 * @a1: high part of first number
 * @a2: low part of first number
 * @b1: high part of second number
 * @b2: low part of second number
 * @count: current count
 */
void print_large_fib(unsigned long a1, unsigned long a2,
	unsigned long b1, unsigned long b2, int count)
{
	unsigned long next1, next2;
	int i;

	for (i = count; i < 98; i++)
	{
		next2 = (a2 + b2) % 1000000000;
		next1 = (a1 + b1) + ((a2 + b2) / 1000000000);
		printf(", %lu", next1);
		if (next2 < 100000000)
			printf("0");
		if (next2 < 10000000)
			printf("0");
		if (next2 < 1000000)
			printf("0");
		if (next2 < 100000)
			printf("0");
		if (next2 < 10000)
			printf("0");
		if (next2 < 1000)
			printf("0");
		if (next2 < 100)
			printf("0");
		if (next2 < 10)
			printf("0");
		printf("%lu", next2);
		a1 = b1;
		a2 = b2;
		b1 = next1;
		b2 = next2;
	}
}

/**
 * main - prints first 98 fibonacci numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long int a = 1, b = 2, next;
	unsigned long int a1, a2, b1, b2;
	int count;

	printf("%lu, %lu", a, b);

	for (count = 2; count < 92; count++)
	{
		next = a + b;
		printf(", %lu", next);
		a = b;
		b = next;
	}

	a1 = a / 1000000000;
	a2 = a % 1000000000;
	b1 = b / 1000000000;
	b2 = b % 1000000000;

	print_large_fib(a1, a2, b1, b2, 92);
	printf("\n");
	return (0);
}
