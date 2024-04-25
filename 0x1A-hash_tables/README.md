#What are Hash Tables?
- Hash tables are a type of data structure used to store key-value pairs. They offer efficient insertion, deletion, and lookup operations by using a hash function to map keys to indices in an array.

##How to Use?
-You can use the hash tables provided in this project by including the necessary header file hash_tables.h in your C code.

##Functions Available
###The following functions are available for use:

hash_table_create(size_t size): Creates a hash table with the specified size.
**hash_table_set(hash_table_t *ht, const char key, const char value): Inserts a key-value pair into the hash table.
**hash_table_get(const hash_table_t ht, const char key): Retrieves the value associated with the given key.
*hash_table_delete(hash_table_t ht): Deletes the hash table and frees allocated memory.
