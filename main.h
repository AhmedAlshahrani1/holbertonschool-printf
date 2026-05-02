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

int print_str(va_list args, flags_t *f, int w);
int print_number(int n); 
int print_unsigned(va_list args, flags_t *f, int w);
int print_octal(va_list args, flags_t *f, int w);
int print_hex(va_list args, flags_t *f, int w);
int print_HEX(va_list args, flags_t *f, int w);

#endif
