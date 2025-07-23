#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i = 0;
	int (*func)(va_list);

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			char spec[2] = {format[i + 1], '\0'};
			func = pick_a_function(spec);

			if (func)
			{
				count += func(args);
				i += 2;
				continue;
			}
			else if (format[i + 1] == '%')
			{
				count += _putchar('%');
				i += 2;
				continue;
			}
			else
			{
				count += _putchar('%');
				count += _putchar(format[i + 1]);
				i += 2;
				continue;
			}
		}
		count += _putchar(format[i]);
		i++;
	}

	va_end(args);
	return count;
}