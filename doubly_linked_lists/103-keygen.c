#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - generates a key for crackme5
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	unsigned int i, sum;
	char *pass = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char key[7];

	if (argc != 2)
	{
		printf("Usage: %s username\n", argv[0]);
		return (1);
	}

	sum = 0;
	for (i = 0; i < strlen(argv[1]); i++)
		sum += argv[1][i];

	key[0] = pass[(sum ^ 59) & 63];
	key[1] = pass[(sum ^ 79) & 63];
	key[2] = pass[(sum ^ 85) & 63];
	key[3] = pass[(sum ^ 111) & 63];
	key[4] = pass[(sum ^ 127) & 63];
	key[5] = pass[(sum ^ 97) & 63];
	key[6] = '\0';

	printf("%s\n", key);
	return (0);
}
