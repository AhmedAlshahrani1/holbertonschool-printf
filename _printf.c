#include "main.h"
#include <stddef.h>

/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, chars = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
		}
		else if (format[i + 1] == '\0')
		{
			va_end(args);
			return (-1);
		}
		else if (format[i + 1] == 'c')
		{
			_putchar(va_arg(args, int));
			i++;
		}
		else if (format[i + 1] == '%')
		{
			_putchar('%');
			i++;
		}
		else
		{
			_putchar(format[i]);
		}
		chars++;
		i++;
	}
	va_end(args);
	return (chars);
}
