#include "main.h"

/**
 * print_str - prints a string with padding
 * @args: va_list
 * @f: pointer to flags struct
 * @w: width
 * Return: number of chars printed
 */
int print_str(va_list args, flags_t *f, int w)
{
	char *str = va_arg(args, char *);
	int i = 0, len = 0, pad;

	if (str == NULL)
		str = "(null)";

	while (str[len])
		len++;

	pad = (w > len) ? (w - len) : 0;

	if (f->minus == 0) /* Pad before if no minus flag */
	{
		for (i = 0; i < pad; i++)
			_putchar(' ');
	}

	for (i = 0; str[i]; i++)
		_putchar(str[i]);

	if (f->minus == 1) /* Pad after if minus flag exists */
	{
		for (i = 0; i < pad; i++)
			_putchar(' ');
	}

	return (len > w ? len : w);
}
