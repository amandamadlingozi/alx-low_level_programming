#include "hash_tables.h"

/**
 * hash_table_set - Add an element to the hash table
 * @ht: Pointer to the hash table
 * @key: Key to add
 * @value: Value associated with the key
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    hash_node_t *new_node, *temp;
    char *key_copy, *value_copy;

    if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
        return 0;

    /* Calculate index */
    index = key_index((const unsigned char *)key, ht->size);

    /* Check if key exists, update value if it does */
    temp = ht->array[index];
    while (temp != NULL)
    {
        if (strcmp(temp->key, key) == 0)
        {
            free(temp->value); /* Free previous value */
            temp->value = malloc(strlen(value) + 1); /* Allocate memory for new value */
            if (temp->value == NULL)
                return 0; /* malloc failed */
            strcpy(temp->value, value); /* Copy value */
            return 1; /* Key found and value updated */
        }
        temp = temp->next;
    }

    /* Key doesn't exist, create new node */
    new_node = malloc(sizeof(hash_node_t));
    if (new_node == NULL)
        return 0; /* malloc failed */

    /* Duplicate key and value */
    key_copy = malloc(strlen(key) + 1);
    if (key_copy == NULL)
    {
        free(new_node);
        return 0; /* malloc failed */
    }
    strcpy(key_copy, key);

    value_copy = malloc(strlen(value) + 1);
    if (value_copy == NULL)
    {
        free(new_node);
        free(key_copy);
        return 0; /* malloc failed */
    }
    strcpy(value_copy, value);

    /* Insert new node at the beginning of the list */
    new_node->key = key_copy;
    new_node->value = value_copy;
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return 1; /* New key-value pair added successfully */
}
