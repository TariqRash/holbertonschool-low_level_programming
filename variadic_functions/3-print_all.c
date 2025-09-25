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
	int found;

	va_start(args, format);

	while (format && format[i])
	{
		found = 0;
		if (format[i] == 99)
			printf("%s%c", sep, va_arg(args, int)), found = 1;
		if (format[i] == 105)
			printf("%s%d", sep, va_arg(args, int)), found = 1;
		if (format[i] == 102)
			printf("%s%f", sep, va_arg(args, double)), found = 1;
		if (format[i] == 115)
			str = va_arg(args, char *), printf("%s%s", sep, str ? str : "(nil)"), found = 1;
		
		sep = found ? ", " : sep;
		i++;
	}

	printf("\n");
	va_end(args);
}
