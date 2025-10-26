# Hash Tables

Implementation of hash table data structure in C using chaining for collision handling.

## Description

This project implements a hash table with the following features:
- Dynamic hash table creation
- djb2 hash algorithm
- Collision handling using chaining
- Key-value pair storage and retrieval
- Hash table printing and deletion

## Files

| File | Description |
|------|-------------|
| `hash_tables.h` | Header file with structures and prototypes |
| `0-hash_table_create.c` | Creates a hash table |
| `1-djb2.c` | Implements djb2 hash algorithm |
| `2-key_index.c` | Calculates index from key |
| `3-hash_table_set.c` | Adds/updates key-value pairs |
| `4-hash_table_get.c` | Retrieves values by key |
| `5-hash_table_print.c` | Prints hash table contents |
| `6-hash_table_delete.c` | Deletes hash table |

## Data Structures

### Hash Node
```c
typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;
```

### Hash Table
```c
typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;
```

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hash_table
```

## Usage Example

```c
hash_table_t *ht = hash_table_create(1024);
hash_table_set(ht, "key", "value");
char *value = hash_table_get(ht, "key");
hash_table_print(ht);
hash_table_delete(ht);
```

## Author

Tariq Almutairi Rasheed Tariq
