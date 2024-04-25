#include "hash_tables.h"

/**
* shash_table_create - Creates a hash table
 *
 * Description: Initializes and allocates memory for a sorted hash table
 * with a specified size.
 *
 * @size: The size of the array
 *
 * Return: A pointer to the newly created hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_table;
	unsigned long int index;

	new_table = (shash_table_t *) malloc(sizeof(shash_table_t));
	if (new_table == NULL)
		return (NULL);
	new_table->size = size;
	new_table->shead = NULL;
	new_table->stail = NULL;
	new_table->array = (shash_node_t **) malloc(sizeof(shash_node_t *) * size);
	if (new_table->array == NULL)
	{
		free(new_table);
		return (NULL);
	}
	for (index = 0; index < size; index++)
		(new_table->array)[index] = NULL;
	return (new_table);
}

/**
* shash_sorted_list_update - Updates value of node in sorted linked list
 *
 * Description: Searches for a node with the given key in the sorted linked
 * list of the sorted hash table. If found, updates its value with the given
 * value.
 *
 * @ht: Pointer to the sorted hash table
 * @new_node: Node to update
 * @key: Key associated with the node
 * @value: New value to update
 *
 * Return: 1 if node updated successfully, 0 otherwise
 */
int shash_sorted_list_update(shash_table_t **ht, shash_node_t **new_node,
		const char *key, const char *value)
{
	shash_node_t *old_head = NULL;

	old_head = (*ht)->shead;
	while (old_head)
	{
		if (strcmp(old_head->key, key) == 0)
		{
			free(old_head->value);
			old_head->value = (char *) strdup(value);
			free((*new_node)->key);
			free((*new_node)->value);
			free((*new_node));
			return (1);
		}
		old_head = old_head->snext;
	}
	return (0);
}

/**
* shash_sorted_list_insert - Inserts node into sorted linked list
 *
 * Description: Inserts a new node into the sorted linked list of the
 * sorted hash table, maintaining the order of keys in ascending order.
 *
 * @ht: Pointer to the sorted hash table
 * @new_node: Node to insert
 * @key: Key associated with the node
 *
 * Return: 1 on success, 0 on failure
 */
int shash_sorted_list_insert(shash_table_t **ht, shash_node_t **new_node,
		const char *key)
{
	shash_node_t *old_head = NULL;

	old_head = (*ht)->shead;
	while (old_head)
	{
		if (strcmp(old_head->key, key) > 0)
		{
			(*new_node)->snext = old_head;
			(*new_node)->sprev = old_head->sprev;
			if (old_head->sprev != NULL)
				old_head->sprev->snext = *new_node;
			else
				(*ht)->shead = *new_node;
			old_head->sprev = *new_node;
			return (1);
		}
/**                                                                                * shash_sorted_list_update - Updates value of node in sorted linked list            *                                                                                  * Description: Searches for a node with the given key in the sorted linked         * list of the sorted hash table. If found, updates its value with the given        * value.                                                                           *                                                                                  * @ht: Pointer to the sorted hash table                                            * @new_node: Node to update                                                        * @key: Key associated with the node                                               * @value: New value to update                                                      *                                                                                  * Return: 1 if node updated successfully, 0 otherwise                              */                                                                                int shash_sorted_list_update(shash_table_t **ht, shash_node_t **new_node,                          const char *key, const char *value)                                {                                                                                          shash_node_t *old_head = NULL;                                                                                                                                        old_head = (*ht)->shead;                                                           while (old_head)                                                                   {                                                                                          if (strcmp(old_head->key, key) == 0)                                               {                                                                                          free(old_head->value);                                                             old_head->value = (char *) strdup(value);                                          free((*new_node)->key);                                                            free((*new_node)->value);                                                          free((*new_node));                                                                 return (1);                                                                }                                                                                  old_head = old_head->snext;                                                }                                                                                  return (0);                                                                }                                                                                                                
	}e
	(*new_node)->sprev = (*ht)->stail;
	(*ht)->stail->snext = *new_node;
	(*ht)->stail = *new_node;
	return (1);
}

/**
  * shash_insert_into_sorted_list - Inserts key-value pair into sorted list
 *
 * Description: Inserts a key-value pair into the sorted linked list of the
 * sorted hash table, maintaining the order of keys in ascending order.
 *
 * @ht: Pointer to the sorted hash table
 * @key: Key to insert
 * @value: Value associated with the key
 *
 * Return: 1 on success, 0 on failure
 */
int shash_insert_into_sorted_list(shash_table_t *ht, const char *key,
		const char *value)
{
	shash_node_t *new_node = NULL;

	new_node = (shash_node_t *) malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->key = (char *) strdup(key);
	new_node->value = (char *) strdup(value);
	new_node->next = new_node->snext = new_node->sprev = NULL;
	if (ht->shead == NULL && ht->stail == NULL)
	{
		ht->shead = new_node;
		ht->stail = new_node;
		return (1);
	}
	else
	{
		if (!shash_sorted_list_update(&ht, &new_node, key, value))
			return (shash_sorted_list_insert(&ht, &new_node, key));
		else
			return (1);
	}
}

/**
 * shash_insert_into_array - Inserts key-value pair into array
 *
 * Description: Inserts a key-value pair into the array of the sorted hash
 * table, either by updating an existing key's value or creating a new entry.
 *
 * @ht: Pointer to the sorted hash table
 * @key: Key to insert or update
 * @value: Value associated with the key
 *
 * Return: 1 on success, 0 on failure
 */
int shash_insert_into_array(shash_table_t *ht, const char *key,
		const char *value)
{
	unsigned long int index = 0;
	shash_node_t *new_node = NULL, *old_head = NULL;

	new_node = (shash_node_t *) malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);
	index = key_index((const unsigned char *) key, ht->size);
	new_node->key = (char *) strdup(key);
	new_node->value = (char *) strdup(value);
	new_node->next = new_node->snext = new_node->sprev = NULL;

	if ((ht->array)[index] == NULL)
	{
		(ht->array)[index] = new_node;
		return (1);
	}
	else
	{
		old_head = (ht->array)[index];
		while (old_head)
		{
			if (strcmp(old_head->key, key) == 0)
			{
				free(old_head->value);
				old_head->value = (char *) strdup(value);
				free(new_node->key);
				free(new_node->value);
				free(new_node);
				return (1);
			}
			old_head = old_head->next;
		}
		old_head = (ht->array)[index];
		new_node->next = old_head;
		(ht->array)[index] = new_node;
		return (1);
	}
}

/**
* shash_table_set - Sets a key-value pair in the sorted hash table
 *
 * Description: Inserts or updates a key-value pair in the sorted hash table.
 * If the key already exists, its corresponding value is updated; otherwise,
 * a new entry is created.
 *
 * @ht: Pointer to the sorted hash table
 * @key: Key to insert or update
 * @value: Value associated with the key
 *
 * Return: 1 on success, 0 on failure
 */

int shash_table_set(
		shash_table_t *ht,
		const char *key,
		const char *value
		);


{
	if (key == NULL || value == NULL || ht == NULL)
		return (0);
	if (strlen(key) == 0)
		return (0);
	if (!shash_insert_into_array(ht, key, value))
		return (0);
	return (shash_insert_into_sorted_list(ht, key, value));
}

/**
 * * shash_table_get - Retrieves value associated with a key
 *
 * Description: Searches for key in sorted hash table and returns its value.
 *
 * @ht: Pointer to sorted hash table
 * @key: Key to search for
 *
 * Return: Value associated with key, or NULL if key is not found
*/
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *current_node;

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


/**
 * shash_table_print - Prints the key/value pairs in a sorted hash table
 * @ht: A pointer to the sorted hash table
 *
 * Description: This function prints the key/value pairs in a sorted hash
 * table. If the hash table is NULL, it does nothing.
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current_node;
	int is_first_hash;

	if (ht == NULL)
		return;
	printf("{");
	is_first_hash = 1;
	current_node = ht->shead;
	while (current_node)
	{
		if (!is_first_hash)
			printf(", ");
		is_first_hash = 0;
		printf("\'%s\': \'%s\'", current_node->key,
				current_node->value);
		current_node = current_node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the key/value pairs in a sorted hash table in
 * reverse
 * @ht: A pointer to the sorted hash table
 *
 * Description: This function prints the key/value pairs in a sorted hash table
 * in reverse order. If the hash table is NULL, it does nothing.
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current_node;
	int is_first_hash;

	if (ht == NULL)
		return;
	printf("{");
	is_first_hash = 1;
	current_node = ht->stail;
	while (current_node)
	{
		if (!is_first_hash)
			printf(", ");
		is_first_hash = 0;
		printf("\'%s\': \'%s\'", current_node->key,
				current_node->value);
		current_node = current_node->sprev;
	}
	printf("}\n");
}


/**
 * shash_table_delete_arr - Deletes sorted hash table's array
 *
 * Description: Frees memory allocated to array elements and their nodes.
 *
 * @ht: Pointer to sorted hash table
 *
 * Return: No return value
 */

void shash_table_delete_arr(shash_table_t *ht)
{
	shash_node_t *current_node, *previous_node;
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

/**
 * shash_table_delete_slist - Deletes sorted hash table's linked list
 *
 * Description: Frees memory allocated to linked list elements.
 *
 * @ht: Pointer to sorted hash table
 *
 * Return: No return value
 */

void shash_table_delete_slist(const shash_table_t *ht)
{
	shash_node_t *current_node, *previous_node;

	if (ht == NULL)
		return;
	current_node = ht->shead;
	previous_node = NULL;
	while (current_node)
	{
		previous_node = current_node;
		current_node = current_node->snext;
		free(previous_node->key);
		free(previous_node->value);
		free(previous_node);
	}
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: Pointer to the sorted hash table to delete
 *
 * Description: This function deletes a sorted hash table and frees all its
 * allocated memory.
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_table_delete_slist(ht);
	shash_table_delete_arr(ht);
}
