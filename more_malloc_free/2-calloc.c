#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array, using malloc
 * @nmemb: number of elements
 * @size: size of each element in bytes
 *
 * Description: The _calloc function allocates memory for an array of
 * nmemb elements of size bytes each and returns a pointer to the
 * allocated memory. The memory is set to zero. If nmemb or size is 0,
 * then _calloc returns NULL. If malloc fails, then _calloc returns NULL.
 *
 * Return: pointer to allocated memory, or NULL if it fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i, total_size;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total_size = nmemb * size;

	ptr = malloc(total_size);

	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < total_size; i++)
		ptr[i] = 0;

	return (ptr);
}
