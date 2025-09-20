#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - frees memory allocated for a struct dog
 * @d: struct dog to free
 *
 * Description: This function frees dogs.
 */
void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
