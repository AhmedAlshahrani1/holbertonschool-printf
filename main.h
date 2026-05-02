#ifndef MAIN_H
#define MAIN_H

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

/* Prototypes */
int _printf(const char *format, ...);
int _putchar(char c);
int get_flags(char s, flags_t *f);
int print_number(int n);
int print_str(char *str);

#endif
