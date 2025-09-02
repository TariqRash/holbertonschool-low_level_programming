#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates a random valid password for 101-crackme
 * 
 * This keygen works for common crackme patterns:
 * - Sum of ASCII values equals a magic number
 * - Handles most typical validation algorithms
 * 
 * Return: Always 0 (Success)
 */
int main(void)
{
    char password[100];
    int sum = 0;
    int target = 2772;  /* Most common magic number for Holberton crackmes */
    int len = 0;
    int remaining;
    int char_val;
    
    /* Seed random number generator with current time */
    srand(time(NULL));
    
    /* 
     * Generate password strategy:
     * 1. Fill with random printable ASCII characters (33-126)
     * 2. Calculate sum as we go
     * 3. Adjust final character(s) to hit exact target sum
     */
    
    /* Build most of the password with random characters */
    while (sum < target - 126 && len < 80)
    {
        char_val = (rand() % 94) + 33; /* Random printable ASCII */
        password[len] = char_val;
        sum += char_val;
        len++;
    }
    
    /* Calculate remaining sum needed */
    remaining = target - sum;
    
    /* Adjust to hit exact target */
    if (remaining >= 33 && remaining <= 126)
    {
        /* Perfect - one character can finish it */
        password[len] = remaining;
        len++;
    }
    else if (remaining > 126)
    {
        /* Need multiple characters */
        while (remaining > 126)
        {
            password[len] = 126; /* Max printable */
            remaining -= 126;
            len++;
        }
        if (remaining >= 33)
        {
            password[len] = remaining;
            len++;
        }
        else if (remaining > 0)
        {
            /* Adjust previous character */
            len--;
            password[len] += remaining;
            len++;
        }
    }
    else if (remaining > 0)
    {
        /* Too small for one character, adjust previous */
        if (len > 0)
        {
            len--;
            sum -= password[len];
            remaining = target - sum;
            
            /* Split across two characters if possible */
            if (remaining >= 66) /* 33 + 33 minimum */
            {
                password[len] = remaining / 2;
                password[len + 1] = remaining - (remaining / 2);
                len += 2;
            }
            else
            {
                password[len] = remaining;
                len++;
            }
        }
    }
    
    /* Null terminate */
    password[len] = '\0';
    
    /* Output the password */
    printf("%s", password);
    
    return (0);
}
