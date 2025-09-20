
#include <stdio.h>

#include <stdlib.h>

#include <ctype.h>

#include <string.h>

/**

 * error_exit - Prints "Error" and exits with status 98.

 * This is the petty way to tell users: "You screwed up".

 */

void error_exit(void)

{

    printf("Error\n");

    exit(98);

}

/**

 * is_digits - Checks if a string is composed only of digits.

 * @s: input string

 * Return: 1 if true, 0 otherwise

 */

int is_digits(char *s)

{

    int i = 0;

    while (s[i])

    {

        if (!isdigit((unsigned char)s[i]))

            return (0);

        i++;

    }

    return (1);

}

/**

 * multiply - Multiplies two positive numbers represented as strings.

  Uses grade-school multiplication (O(nm)), because why reinvent the wheel?

 * @num1: first number string

 * @num2: second number string

 * Return: result string (caller must free)

 */

char multiply(char num1, char *num2)

{

    int len1 = strlen(num1), len2 = strlen(num2);

    int result = calloc(len1 + len2, sizeof(int)); / safe init to 0 */

    char *res_str;

    int i, j, carry, sum;

    if (!result)

        error_exit();

    /* Multiply digit by digit */

    for (i = len1 - 1; i >= 0; i--)

    {

        for (j = len2 - 1; j >= 0; j--)

        {

            sum = (num1[i] - '0') * (num2[j] - '0');

            sum += result[i + j + 1]; /* add existing value */

            result[i + j + 1] = sum % 10;

            result[i + j] += sum / 10;

        }

    }

    /* Convert int array to string (skip leading zeros) */

    i = 0;

    while (i < (len1 + len2) && result[i] == 0)

        i++;

    if (i == len1 + len2) /* all zeros */

    {

        res_str = strdup("0");

        free(result);

        return res_str;

    }

    res_str = malloc((len1 + len2 - i + 1) * sizeof(char));

    if (!res_str)

    {

        free(result);

        error_exit();

    }

    j = 0;

    while (i < (len1 + len2))

        res_str[j++] = result[i++] + '0';

    res_str[j] = '\0';

    free(result); /* petty cleanup, no leaks allowed */

    return res_str;

}

/**

 * main - Multiplies two positive numbers.

 * Usage: mul num1 num2

 * Return: 0 on success, 98 on error

 */

int main(int argc, char *argv[])

{

    char *res;

    if (argc != 3)

        error_exit();

    if (!is_digits(argv[1]) || !is_digits(argv[2]))

        error_exit();

    res = multiply(argv[1], argv[2]);

    printf("%s\n", res);

    free(res); /* petty memory hygiene */

    return (0);

}

