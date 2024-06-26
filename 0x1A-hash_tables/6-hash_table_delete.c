#include "hash_tables.h"

/**
* hash_table_delete - Deletes a hash table
 *
 * Description: Frees memory allocated for the hash table and its elements.
 *
 * @ht: Hash table to delete
 *
 * Return: No return value
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *current_node, *previous_node;
	unsigned long int array_index, has_nodes;

	for (array_index = 0; array_index < ht->size; array_index++)
	{
		has_nodes = 0;
		current_node = (ht->array)[array_index];
		while (current_node)
		{
			has_nodes = 1;
			previous_node = current_node;
			current_node = current_node->next;
			free(previous_node->key);
			free(previous_node->value);
			free(previous_node);
		}
		if (!has_nodes)
			free((ht->array)[array_index]);
	}
	free(ht->array);
	free(ht);

}
