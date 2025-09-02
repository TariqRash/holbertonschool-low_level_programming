# C - More functions, nested loops

This project covers more advanced C programming concepts including character validation, mathematical operations, and complex printing patterns.

## Learning Objectives

- How to use nested loops
- What is a function and how do you use functions
- What is the difference between a declaration and a definition of a function
- What is a prototype
- Scope of variables
- What are the gcc flags -Wall -Werror -Wextra -pedantic -std=gnu89
- What are header files and how to to use them with #include

## Files

### Mandatory Tasks
- `0-isupper.c` - Checks for uppercase character
- `1-isdigit.c` - Checks for a digit (0 through 9)
- `2-mul.c` - Multiplies two integers
- `3-print_numbers.c` - Prints numbers from 0 to 9
- `4-print_most_numbers.c` - Prints numbers 0 to 9, except 2 and 4
- `5-more_numbers.c` - Prints 10 times the numbers 0 to 14
- `6-print_line.c` - Draws a straight line in terminal
- `7-print_diagonal.c` - Draws a diagonal line
- `8-print_square.c` - Prints a square
- `9-fizz_buzz.c` - Classic FizzBuzz program
- `10-print_triangle.c` - Prints a triangle

### Advanced Tasks
- `100-prime_factor.c` - Finds largest prime factor of 612852475143
- `101-print_number.c` - Prints an integer using only _putchar

## Compilation

All files are compiled with:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89
```

For the prime factor program:
```
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 100-prime_factor.c -o 100-prime_factor -lm
```
