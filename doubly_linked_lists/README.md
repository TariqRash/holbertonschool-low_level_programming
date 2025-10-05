# Doubly Linked Lists

This project covers the fundamentals of doubly linked lists in C.

## Learning Objectives
- What is a doubly linked list
- How to use doubly linked lists
- Differences between singly and doubly linked lists

## Data Structure
```c
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;
```

## Files
- `lists.h` - Header file with all prototypes and struct definition
- `0-print_dlistint.c` - Print all elements of a doubly linked list
- `1-dlistint_len.c` - Return the number of elements
- `2-add_dnodeint.c` - Add node at the beginning
- `3-add_dnodeint_end.c` - Add node at the end
- `4-free_dlistint.c` - Free a doubly linked list
- `5-get_dnodeint.c` - Get node at index
- `6-sum_dlistint.c` - Sum all data in the list
- `7-insert_dnodeint.c` - Insert node at given position
- `8-delete_dnodeint.c` - Delete node at index
- `100-password` - Password for crackme4
- `102-result` - Largest palindrome from product of two 3-digit numbers
- `103-keygen.c` - Keygen for crackme5

## Compilation
All files compiled with: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`

## Author
Holberton School Project
