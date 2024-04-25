#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_create - Create a hash table
 * @size: The size of the array
 *
 * Return: Pointer to the newly created hash table, or NULL if failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;

    /* Allocate memory for hash table structure */
	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return NULL;

    /* Allocate memory for array of hash nodes */
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return NULL;
	}

    /* Initialize all elements of the array to NULL */
	for (unsigned long int i = 0; i < size; ++i)
		ht->array[i] = NULL;
	
	ht->size = size;
	
	return ht;
}
