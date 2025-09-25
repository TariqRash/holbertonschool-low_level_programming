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
		if (format[i] == 99 || format[i] == 105 || format[i] == 102 || format[i] == 115)
			printf("%s", sep), sep = ", ";

		format[i] == 99 && printf("%c", va_arg(args, int));
		format[i] == 105 && printf("%d", va_arg(args, int));
		format[i] == 102 && printf("%f", va_arg(args, double));
		if (format[i] == 115)
			str = va_arg(args, char *), printf("%s", str && *str ? str : "(nil)");

		i++;
	}

	printf("\n");
	va_end(args);
}
