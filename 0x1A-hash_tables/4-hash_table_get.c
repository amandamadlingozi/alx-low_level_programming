#include "hash_tables.h"

/**
* hash_table_get - Retrieves value associated with a key
 *
 * Description: Searches for the key in the hash table and returns the
 * corresponding value if found.
 *
 * @ht: Hash table
 * @key: Key to search for
 *
 * Return: Value associated with the key, or NULL if key is not found
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current_node;

	if (ht == NULL || key == NULL)
		return (NULL);
	index = key_index((const unsigned char *) key, ht->size);
	if ((ht->array)[index] == NULL)
		return (NULL);
	current_node = (ht->array)[index];
	while (current_node)
	{
		if (strcmp(current_node->key, key) == 0)
			return (current_node->value);
		current_node = current_node->next;
	}
	return (NULL);

}
