#include "main.h"
#include <stddef.h>

int print_str(char *str);
int print_number(int n);

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
 * print_number - prints an integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_number(int n)
{
	unsigned int num;
	int chars = 0;

	if (n < 0)
	{
		chars += _putchar('-');
		num = -n;
	}
	else
		num = n;
	if (num / 10)
		chars += print_number(num / 10);
	chars += _putchar((num % 10) + '0');
	return (chars);
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
		else
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}
			if (format[i] == 'c')
				_putchar(va_arg(args, int));
			else if (format[i] == 's')
				chars += print_str(va_arg(args, char *)) - 1;
			else if (format[i] == 'd' || format[i] == 'i')
				chars += print_number(va_arg(args, int)) - 1;
			else if (format[i] == '%')
				_putchar('%');
			else
			{
				_putchar('%');
				_putchar(format[i]);
				chars++;
			}
		}
		chars++;
		i++;
	}
	va_end(args);
	return (chars);
}
