#include "main.h"
#include <stdlib.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1, On error -1
 */
int _putchar(char c);

/**
 * is_digit - checks if string contains only digits
 * @s: string to check
 * Return: 1 if all digits, 0 otherwise
 */
int is_digit(char *s)
{
    int i = 0;
    
    if (!s || !s[0])
        return (0);
    
    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

/**
 * _strlen - returns length of string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
    int len = 0;
    
    if (!s)
        return (0);
    
    while (s[len])
        len++;
    return (len);
}

/**
 * multiply - multiplies two number strings
 * @num1: first number string
 * @num2: second number string
 * Return: result string (must be freed)
 */
char *multiply(char *num1, char *num2)
{
    int len1, len2, len_result, i, j, carry, mul, val1, val2, sum;
    char *result;
    
    len1 = _strlen(num1);
    len2 = _strlen(num2);
    len_result = len1 + len2;
    
    result = malloc(sizeof(char) * (len_result + 1));
    if (!result)
        return (NULL);
    
    /* Initialize result array */
    for (i = 0; i <= len_result; i++)
        result[i] = 0;
    
    /* Reverse multiply like elementary school method */
    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        val1 = num1[i] - '0';
        
        for (j = len2 - 1; j >= 0; j--)
        {
            val2 = num2[j] - '0';
            mul = val1 * val2;
            sum = mul + result[i + j + 1] + carry;
            carry = sum / 10;
            result[i + j + 1] = sum % 10;
        }
        
        if (carry > 0)
            result[i + j + 1] += carry;
    }
    
    /* Convert result to string */
    for (i = 0; i < len_result; i++)
        result[i] += '0';
    
    result[len_result] = '\0';
    
    /* Find first non-zero digit */
    i = 0;
    while (result[i] == '0' && i < len_result - 1)
        i++;
    
    /* Shift result to remove leading zeros */
    if (i > 0)
    {
        for (j = 0; j <= len_result - i; j++)
            result[j] = result[j + i];
    }
    
    return (result);
}

/**
 * print_error - prints Error and exits
 */
void print_error(void)
{
    _putchar('E');
    _putchar('r');
    _putchar('r');
    _putchar('o');
    _putchar('r');
    _putchar('\n');
    exit(98);
}

/**
 * print_string - prints a string using _putchar
 * @s: string to print
 */
void print_string(char *s)
{
    int i = 0;
    
    if (!s)
        return;
    
    while (s[i])
    {
        _putchar(s[i]);
        i++;
    }
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
    char *result;
    
    /* Check argument count */
    if (argc != 3)
        print_error();
    
    /* Check if arguments are valid numbers */
    if (!is_digit(argv[1]) || !is_digit(argv[2]))
        print_error();
    
    /* Special case: if either number is "0" */
    if ((_strlen(argv[1]) == 1 && argv[1][0] == '0') ||
        (_strlen(argv[2]) == 1 && argv[2][0] == '0'))
    {
        _putchar('0');
        _putchar('\n');
        return (0);
    }
    
    /* Multiply the numbers */
    result = multiply(argv[1], argv[2]);
    if (!result)
        print_error();
    
    /* Print result */
    print_string(result);
    _putchar('\n');
    
    /* Clean up memory */
    free(result);
    
    return (0);
}
