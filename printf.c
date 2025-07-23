#include <stdio.h>
#include "main.h"
#include <stdarg.h>

/**
 * specifiers_list - Returns a static array of specifiers
 * and pointers to their associated handling functions.
 *
 * Return: Pointer to an array of type_specifier structures.
 */
type_specifier *specifiers_list(void)
{
	static type_specifier symbol[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_integer},
		{'i', print_integer},
		{'\0', NULL}
	};

	return (symbol);
}

/**
 * print_unknown_char - Handles the display of an unknown specifier.
 * @c: Unknown character to display after '%'.
 *
 * Return: Number of characters printed (always 2).
 */
int print_unknown_char(char c)
{
	_putchar('%');
	_putchar(c);
	return (2);
}

/**
 * match_specifier - Matches a specifier with its corresponding print function.
 * @symbol: Array of specifiers and corresponding functions.
 * @c: Character to compare after '%'.
 * @arguments: Variadic arguments list.
 *
 * Return: Number of characters printed.
 */
int match_specifier(type_specifier *symbol, char c, va_list arguments)
{
	int i = 0;

	while (symbol[i].specifier != '\0')
	{
		if (c == symbol[i].specifier)
			return (symbol[i].print_func(arguments));
		i++;
	}
	return (print_unknown_char(c));
}

/**
 * _printf - Simplified reimplementation of the printf function.
 * @format: Format string to parse.
 *
 * Return: Total number of characters printed, or -1 on error.
 */
int _printf(const char *format, ...)
{
	va_list arguments;
	int k = 0, count = 0;

	if (format == NULL)
		return (-1);

	va_start(arguments, format);

	while (format[k])
	{
		if (format[k] == '%')
		{
			if (format[k + 1] == '\0')
				return (-1);
			k++;
			count += match_specifier(specifiers_list(), format[k], arguments);
		}
		else
		{
			_putchar(format[k]);
			count++;
		}
		k++;
	}

	va_end(arguments);
	return (count);
}
