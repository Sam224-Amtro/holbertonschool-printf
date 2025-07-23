#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

int (*pick_a_function(char *s))(va_list)
{
	specifier_f function[] = {
		{"c", print_character},
		{"s", print_string},
		{"d", print_integer},
		{"i", print_integer},
		{NULL, NULL}
	};
	int i = 0;

	while (function[i].specifier != NULL)
	{
		if (strcmp(function[i].specifier, s) == 0)
			return (function[i].function);
		i++;
	}

	return (NULL);
}

int _putchar(char c)
{
	write(1, &c, 1);
}

int print_character(va_list args)
{
	char c = va_arg(args, char );

	_putchar(c);
	return (1);
}

int print_string(va_list args)
{
	char *str = va_arg(args,char *);
	int i = 0;

	if (!str)
		str = "(NULL)";
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

int print_integer(va_list args)
{
	int n = va_arg(args, int);

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	/**
	 * On rend le chiffre postif pour eviter
	 * un mauvais comportement avec Modulo.
	 */
	if (n / 10)
		print_integer(n / 10);
	_putchar(n % 10 + '0');
}
