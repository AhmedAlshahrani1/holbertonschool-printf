#include "main.h"

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
			/* Reset flags and width for every specifier */
			flags.minus = 0;
			width = 0;

			/* Parse flags like '-' */
			while (get_flags(format[i], &flags))
				i++;

			/* Parse field width */
			while (format[i] >= '0' && format[i] <= '9')
			{
				width = (width * 10) + (format[i] - '0');
				i++;
			}

			if (format[i] == '\0')
				break;

			/* Handle all required specifiers */
			if (format[i] == 'c')
				chars += _putchar(va_arg(args, int));
			else if (format[i] == 's')
				chars += print_str(args, &flags, width);
			else if (format[i] == 'd' || format[i] == 'i')
				chars += print_number(va_arg(args, int));
			else if (format[i] == 'u')
				chars += print_unsigned(args, &flags, width);
			else if (format[i] == 'o')
				chars += print_octal(args, &flags, width);
			else if (format[i] == 'x')
				chars += print_hex(args, &flags, width);
			else if (format[i] == 'X')
				chars += print_HEX(args, &flags, width);
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
