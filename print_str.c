#include "main.h"

/**
 * print_str - prints a string
 * @args: va_list of arguments
 * @f: pointer to flags
 * Return: number of characters printed
 */
int print_str(va_list args, flags_t *f)
{
	char *str = va_arg(args, char *);
	int i = 0;

	if (str == NULL)
		str = "(null)";

	/* If minus flag is 1, logic for left-justification goes here */
	/* For now, we simply print the string to maintain basic flow */
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}
