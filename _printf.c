#include "main.h"

/**
 * print_number - prints a signed integer with width/flags
 */

int print_number(va_list args, flags_t *f, int w)
{
	long int n = va_arg(args, int);
	long int tmp = n;
	int len = 0, i, pad;
	char buf[20];

	if (n < 0) {
		len++;
		tmp = -tmp;
	}
	if (tmp == 0) buf[len++] = '0';
	while (tmp > 0) {
		buf[len++] = (tmp % 10) + '0';
		tmp /= 10;
	}

	pad = (w > len) ? (w - len) : 0;
	if (f->minus == 0)
		for (i = 0; i < pad; i++) _putchar(' ');

	if (n < 0) _putchar('-');
	for (i = len - 1; i >= (n < 0 ? 1 : 0); i--) _putchar(buf[i]);

	if (f->minus == 1)
		for (i = 0; i < pad; i++) _putchar(' ');

	return (len > w ? len : w);
}
/**
 * print_base - helper for unsigned, octal, and hex
 */
int print_base(unsigned int n, int base, int uppercase, flags_t *f, int w)
{
	char *set = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	char buf[64];
	int len = 0, i, pad;

	if (n == 0) buf[len++] = '0';
	while (n > 0) {
		buf[len++] = set[n % base];
		n /= base;
	}

	pad = (w > len) ? (w - len) : 0;
	if (f->minus == 0)
		for (i = 0; i < pad; i++) _putchar(' ');
	for (i = len - 1; i >= 0; i--) _putchar(buf[i]);
	if (f->minus == 1)
		for (i = 0; i < pad; i++) _putchar(' ');

	return (len > w ? len : w);
}

/* Specific wrappers for the references needed */
int print_unsigned(va_list args, flags_t *f, int w)
{ return print_base(va_arg(args, unsigned int), 10, 0, f, w); }

int print_octal(va_list args, flags_t *f, int w)
{ return print_base(va_arg(args, unsigned int), 8, 0, f, w); }

int print_hex(va_list args, flags_t *f, int w)
{ return print_base(va_arg(args, unsigned int), 16, 0, f, w); }

int print_HEX(va_list args, flags_t *f, int w)
{ return print_base(va_arg(args, unsigned int), 16, 1, f, w); }

/**
 * _printf - produces output according to a format
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
