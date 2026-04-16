#include "main.h"
#include <stddef.h>

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, printed_chars = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			printed_chars++;
		}
		else
		{
			if (format[i + 1] == '\0')
			{
				va_end(args);
				return (-1);
			}
			if (format[i + 1] == 'c')
			{
				_putchar(va_arg(args, int));
				printed_chars++;
				i++;
			}
			else if (format[i + 1] == '%')
			{
				_putchar('%');
				printed_chars++;
				i++;
			}
			else
			{
				_putchar(format[i]);
				printed_chars++;
			}
		}
		i++;
	}
	va_end(args);
	return (printed_chars);
}
