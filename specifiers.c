#include "main.h"
#include <unistd.h>

int print_int_helper(unsigned int num);

/**
 * print_char - Prints a single character from va_list
 */
int print_char(va_list arguments)
{
	char c = va_arg(arguments, int);

	if (_putchar(c) == -1)
		return (-1);

	return (1);
}

/**
 * print_string - Prints a string from va_list
 */
int print_string(va_list arguments)
{
	int k;
	int counter = 0;
	char *str = va_arg(arguments, char *);

	if (!str)
		str = "(null)";

	for (k = 0; str[k] != '\0'; k++)
	{
		if (_putchar(str[k]) == -1)
			return (-1);
		counter++;
	}

	return (counter);
}
/**
 * print_percent - Prints an percent from va_list
 */
int print_percent(va_list arguments)
{
	(void)arguments;

	if (_putchar('%') == -1)
		return (-1);

	return (1);
}

/**
 * print_int - Prints an integer from va_list
 */
int print_integer(va_list arguments)
{
	long n;
	int count = 0, k = 0;
	char waiting_numbers[20];

	n = (long)va_arg(arguments, int);

	if (n < 0)
	{
		_putchar('-');
		count++;
		n = -n;
	}
	if (n == 0)
	{
		_putchar('0');
		return (count + 1);
	}

	while (n > 0)
	{
		waiting_numbers[k++] = (n % 10) + '0';
		n /= 10;
	}
	while (k--)
	{
		_putchar(waiting_numbers[k]);
		count++;
	}
	return (count);
}
