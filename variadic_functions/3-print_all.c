#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 *
 * Return: Nothing
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
	char *str, *sep = "";

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == 99)
			printf("%s%c", sep, va_arg(args, int)), sep = ", ";
		if (format[i] == 105)
			printf("%s%d", sep, va_arg(args, int)), sep = ", ";
		if (format[i] == 102)
			printf("%s%f", sep, va_arg(args, double)), sep = ", ";
		if (format[i] == 115)
		{
			str = va_arg(args, char *);
			if (str == NULL)
				str = "(nil)";
			printf("%s%s", sep, str);
			sep = ", ";
		}
		i++;
	}

	printf("\n");
	va_end(args);
}
