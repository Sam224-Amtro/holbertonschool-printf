#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdarg.h>

typedef struct specifier_f
{
	char *specifier;
	int (*function)(va_list args);
} specifier_f;

int _printf(const char *format, ...);
int (*pick_a_function(char *s))(va_list);
int _putchar(char c);
int print_character(va_list args);
int print_string(va_list args);
int print_integer(va_list args);

#endif
