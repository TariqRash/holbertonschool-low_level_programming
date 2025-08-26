#include <stdio.h>

/**
 * main - prints first 98 fibonacci numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long int a = 1, b = 2, next;
	unsigned long int a1, a2, b1, b2, next1, next2;
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

	for (count = 92; count < 98; count++)
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
	printf("\n");
	return (0);
}
