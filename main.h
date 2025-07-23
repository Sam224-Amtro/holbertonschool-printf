#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_integer(va_list args);

typedef struct type_specifier
{
	char specifier;
	int (*print_func)(va_list);
} type_specifier;

#endif /* MAIN_H */
