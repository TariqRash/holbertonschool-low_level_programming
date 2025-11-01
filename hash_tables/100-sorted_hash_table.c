#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the array
 * Return: pointer to the newly created hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);
	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (free(ht), NULL);
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;
	return (ht);
}

/**
 * insert_sorted_list - inserts node into sorted linked list
 * @ht: hash table
 * @new: new node to insert
 */
void insert_sorted_list(shash_table_t *ht, shash_node_t *new)
{
	shash_node_t *temp = ht->shead;

	if (temp == NULL)
	{
		ht->shead = ht->stail = new;
		new->sprev = new->snext = NULL;
		return;
	}
	while (temp != NULL)
	{
		if (strcmp(new->key, temp->key) < 0)
		{
			new->snext = temp;
			new->sprev = temp->sprev;
			temp->sprev = new;
			if (new->sprev != NULL)
				new->sprev->snext = new;
			else
				ht->shead = new;
			return;
		}
		temp = temp->snext;
	}
	new->snext = NULL;
	new->sprev = ht->stail;
	ht->stail->snext = new;
	ht->stail = new;
}

/**
 * shash_table_set - adds element to sorted hash table
 * @ht: hash table
 * @key: key string
 * @value: value string
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new, *temp;
	char *value_copy, *key_copy;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = value_copy;
			return (1);
		}
		temp = temp->next;
	}
	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
		return (free(value_copy), 0);
	key_copy = strdup(key);
	if (key_copy == NULL)
		return (free(new), free(value_copy), 0);
	new->key = key_copy;
	new->value = value_copy;
	new->next = ht->array[index];
	ht->array[index] = new;
	insert_sorted_list(ht, new);
	return (1);
}

/**
 * shash_table_get - retrieves value associated with key
 * @ht: hash table
 * @key: key to look for
 * Return: value associated with key, or NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *temp;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints sorted hash table
 * @ht: hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *temp;
	int first = 1;

	if (ht == NULL)
		return;
	printf("{");
	temp = ht->shead;
	while (temp != NULL)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		first = 0;
		temp = temp->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints sorted hash table in reverse
 * @ht: hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *temp;
	int first = 1;

	if (ht == NULL)
		return;
	printf("{");
	temp = ht->stail;
	while (temp != NULL)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		first = 0;
		temp = temp->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes sorted hash table
 * @ht: hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *temp, *next;

	if (ht == NULL)
		return;
	temp = ht->shead;
	while (temp != NULL)
	{
		next = temp->snext;
		free(temp->key);
		free(temp->value);
		free(temp);
		temp = next;
	}
	free(ht->array);
	free(ht);
}
