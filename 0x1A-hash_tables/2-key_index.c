#include "hash_tables.h"

/**
 * key_index - Returns index for a key in hash table array
 *
 * Description: Computes index for a key in hash table array.
 *
 * @key: The key
 * @size: Size of hash table array
 *
 * Return: Index for key/value pair in hash table array
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_results;

	hash_results = hash_djb2(key);
	if (size != 0)
		return (hash_results % size);

	return (0);
}
