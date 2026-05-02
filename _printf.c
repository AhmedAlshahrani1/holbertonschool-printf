#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct flags - struct containing flags to "turn on"
 * @minus: flag for '-'
 */
typedef struct flags
{
	int minus;
} flags_t;

/**
 * get_flags - checks for the '-' flag modifier
 * @s: character to check
 * @f: pointer to the flags struct
 * Return: 1 if flag found, 0 otherwise
 */
int get_flags(char s, flags_t *f)
{
	if (s == '-')
	{
		f->minus = 1;
		return (1);
	}
	return (0);
}

/**
 * print_number - prints an integer (Your original logic)
 * @n: integer to print
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
 * print_str - prints a string with justification/padding support
 * @args: va_list of arguments
 * @f: pointer to flags struct
 * @w: field width
 * Return: number of characters printed
 */
int print_str(va_list args, flags_t *f, int w)
{
	char *str = va_arg(args, char *);
	int i = 0, len = 0, pad;

	if (str == NULL)
		str = "(null)";

	/* Calculate string length */
	while (str[len])
		len++;

	/* Calculate padding */
	pad = (w > len) ? (w - len) : 0;

	/* If NOT left-justified (minus is 0), print spaces BEFORE */
	if (f->minus == 0)
	{
		for (i = 0; i < pad; i++)
			_putchar(' ');
	}

	/* Print the string */
	for (i = 0; str[i]; i++)
		_putchar(str[i]);

	/* If left-justified (minus is 1), print spaces AFTER */
	if (f->minus == 1)
	{
		for (i = 0; i < pad; i++)
			_putchar(' ');
	}

	return (len > w ? len : w);
}

/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, chars = 0, width = 0;
	flags_t flags = {0};

	if (format == NULL || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			chars += _putchar(format[i]);
		}
		else
		{
			i++;
			/* Reset for each specifier */
			flags.minus = 0;
			width = 0;

			/* Check for '-' flag */
			while (get_flags(format[i], &flags))
				i++;

			/* Check for width digits */
			while (format[i] >= '0' && format[i] <= '9')
			{
				width = (width * 10) + (format[i] - '0');
				i++;
			}

			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}

			/* Handle specifiers */
			if (format[i] == 'c')
				chars += _putchar(va_arg(args, int));
			else if (format[i] == 's')
				chars += print_str(args, &flags, width);
			else if (format[i] == 'd' || format[i] == 'i')
				chars += print_number(va_arg(args, int));
			else if (format[i] == '%')
				chars += _putchar('%');
			else
			{
				chars += _putchar('%');
				chars += _putchar(format[i]);
			}
		}
		i++;
	}
	va_end(args);
	return (chars);
}
