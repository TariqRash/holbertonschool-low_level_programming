#include <stdio.h>
#include <math.h>

/**
 * main - finds and prints the largest prime factor of 612852475143
 *
 * Return: Always 0
 */
int main(void)
{
	long number = 612852475143;
	long largest_prime = -1;
	long i;

	/* Remove factors of 2 */
	while (number % 2 == 0)
	{
		largest_prime = 2;
		number = number / 2;
	}

	/* Check for odd factors from 3 onwards */
	for (i = 3; i <= sqrt(number); i = i + 2)
	{
		while (number % i == 0)
		{
			largest_prime = i;
			number = number / i;
		}
	}

	/* If number is still greater than 2, it's a prime */
	if (number > 2)
		largest_prime = number;

	printf("%ld\n", largest_prime);

	return (0);
}
