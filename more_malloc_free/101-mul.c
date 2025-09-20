#include "main.h"
#include <stdlib.h>

int _putchar(char c);

void error_exit(void)
{
    _putchar('E');
    _putchar('r');
    _putchar('r');
    _putchar('o');
    _putchar('r');
    _putchar('\n');
    exit(98);
}

int str_len(char *s)
{
    int len = 0;
    while (s[len]) len++;
    return (len);
}

int is_num(char *s)
{
    int i = 0;
    if (!s[0]) return (0);
    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9') return (0);
        i++;
    }
    return (1);
}

/* Ultra simple: convert to long long if possible */
int main(int argc, char **argv)
{
    unsigned long long n1 = 0, n2 = 0, result;
    int i, len1, len2;
    char temp[64];
    
    if (argc != 3)
        error_exit();
    
    if (!is_num(argv[1]) || !is_num(argv[2]))
        error_exit();
    
    len1 = str_len(argv[1]);
    len2 = str_len(argv[2]);
    
    /* Check for zero */
    if ((len1 == 1 && argv[1][0] == '0') || (len2 == 1 && argv[2][0] == '0'))
    {
        _putchar('0');
        _putchar('\n');
        return (0);
    }
    
    /* If numbers are small enough for unsigned long long */
    if (len1 <= 18 && len2 <= 18)
    {
        /* Convert strings to numbers */
        for (i = 0; i < len1; i++)
            n1 = n1 * 10 + (argv[1][i] - '0');
        for (i = 0; i < len2; i++)
            n2 = n2 * 10 + (argv[2][i] - '0');
        
        result = n1 * n2;
        
        /* Convert back to string and print */
        if (result == 0)
        {
            _putchar('0');
        }
        else
        {
            i = 0;
            while (result > 0)
            {
                temp[i++] = (result % 10) + '0';
                result /= 10;
            }
            while (--i >= 0)
                _putchar(temp[i]);
        }
        _putchar('\n');
        return (0);
    }
    
    /* For very large numbers, fall back to array method */
    /* But use single malloc/free */
    {
        int len_res = len1 + len2;
        int *res = malloc(len_res * sizeof(int));
        int carry, n_1, n_2, sum, j, start;
        
        if (!res) error_exit();
        
        for (i = 0; i < len_res; i++) res[i] = 0;
        
        for (i = len1 - 1; i >= 0; i--)
        {
            carry = 0;
            n_1 = argv[1][i] - '0';
            for (j = len2 - 1; j >= 0; j--)
            {
                n_2 = argv[2][j] - '0';
                sum = n_1 * n_2 + res[i + j + 1] + carry;
                carry = sum / 10;
                res[i + j + 1] = sum % 10;
            }
            if (carry > 0) res[i + j + 1] += carry;
        }
        
        start = 0;
        while (start < len_res && res[start] == 0) start++;
        
        if (start == len_res)
            _putchar('0');
        else
            for (i = start; i < len_res; i++)
                _putchar(res[i] + '0');
        
        _putchar('\n');
        free(res);
        return (0);
    }
}
