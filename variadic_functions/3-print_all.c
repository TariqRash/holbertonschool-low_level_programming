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
	char *str, *separator = "";

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == 99)
		{
			printf("%s%c", separator, va_arg(args, int));
			separator = ", ";
		}
		while (format[i] == 105)
		{
			printf("%s%d", separator, va_arg(args, int));
			separator = ", ";
			break;
		}
		while (format[i] == 102)
		{
			printf("%s%f", separator, va_arg(args, double));
			separator = ", ";
			break;
		}
		while (format[i] == 115)
		{
			str = va_arg(args, char *);
			printf("%s%s", separator, str ? str : "(nil)");
			separator = ", ";
			break;
		}
		i++;
	}

	printf("\n");
	va_end(args);
}
