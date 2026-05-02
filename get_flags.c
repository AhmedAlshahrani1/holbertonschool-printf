#include "main.h"

/**
 * get_flags - turns on flags if _printf finds a flag modifier
 * @s: character that holds the flag specifier
 * @f: pointer to the struct flags where we set the flag
 * Return: 1 if a flag was turned on, 0 otherwise
 */
int get_flags(char s, flags_t *f)
{
	int i = 0;

	if (s == '-')
	{
		f->minus = 1;
		i = 1;
	}
	return (i);
}
