#include "main.h"
#include <stddef.h>

int print_str(char *str);

/**
 * print_str - prints a string
 * @str: string to print
 *
 * Return: number of characters printed
 */
int print_str(char *str)
{
	int j = 0;

	if (str == NULL)
		str = "(null)";
	while (str[j] != '\0')
	{
		_putchar(str[j]);
		j++;
	}
	return (j);
}

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
			_putchar(format[i]);
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
		else if (format[i + 1] == 's')
		{
			chars += print_str(va_arg(args, char *)) - 1;
			i++;
		}
		else if (format[i + 1] == '%')
		{
			_putchar('%');
			i++;
		}
		else
			_putchar(format[i]);
		chars++;
		i++;
	}
	va_end(args);
	return (chars);
}
