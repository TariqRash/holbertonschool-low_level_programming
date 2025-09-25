#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - performs simple operations
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int (*op_func)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	op_func = get_op_func(argv[2]);
	if (op_func == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	if (atoi(argv[3]) == 0 && (*argv[2] == 47 || *argv[2] == 37))
	{
		printf("Error\n");
		exit(100);
	}

	printf("%d\n", op_func(atoi(argv[1]), atoi(argv[3])));
	return (0);
}
