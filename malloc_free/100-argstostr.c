#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	if (s == NULL)
		return (0);

	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * argstostr - concatenates all the arguments of your program
 * @ac: argument count
 * @av: argument vector
 *
 * Description: Returns NULL if ac == 0 or av == NULL. Returns a pointer
 * to a new string, or NULL if it fails. Each argument should be followed
 * by a \n in the new string.
 *
 * Return: pointer to new string, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	char *result;
	int total_len = 0, i, j, k = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
		total_len += _strlen(av[i]) + 1;

	result = malloc(sizeof(char) * (total_len + 1));

	if (result == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			result[k++] = av[i][j];
		result[k++] = '\n';
	}

	result[k] = '\0';

	return (result);
}
