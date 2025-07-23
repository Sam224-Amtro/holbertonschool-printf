#include "main.h"
#include <unistd.h>

int print_int_helper(unsigned int num);

/**
 * print_char - Prints a single character from the argument list.
 * @arguments: A va_list containing the character to print.
 *
 * Return: 1 if the character is printed successfully, -1 on error.
 */
int print_char(va_list arguments)
{
	char c = va_arg(arguments, int);

	if (_putchar(c) == -1)
		return (-1);

	return (1);
}

/**
 * print_string - Prints a string from the argument list.
 * @arguments: A va_list containing the string to print.
 *
 * Return: The number of characters printed, or -1 on error.
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
 * print_percent - Prints the '%' character.
 * @arguments: A va_list (not used in this function).
 *
 * Return: 1 if the percent sign is printed successfully, -1 on error.
 */
int print_percent(va_list arguments)
{
	(void)arguments;

	if (_putchar('%') == -1)
		return (-1);

	return (1);
}

/**
 * print_integer - Prints an integer from the argument list.
 * @arguments: A va_list containing the integer to print.
 *
 * Return: The number of characters printed, or -1 on error.
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
