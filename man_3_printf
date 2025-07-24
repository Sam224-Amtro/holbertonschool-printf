Custom _printf Implementation                          _PRINTF(3)
NAME
       _printf − custom implementation of the standard printf function
SYNOPSIS
       #include <stdarg.h>
       #include "main.h"
       int _printf(const char *format, ...);
DESCRIPTION
       The _printf function produces output according to a specified format.
       It works similarly to the standard C library printf function, with
       limited format specifier support.
PARAMETERS
       format
              A format string containing normal characters and format
              specifiers preceded by the '%' symbol.
       ...    A variable number of arguments corresponding to format
              specifiers in the format string.
FORMAT SPECIFIERS
       %c     Prints a single character.
       %s     Prints a character string. If the string is NULL,
              prints "(null)".
       %%     Prints the percent character '%'.
       %d     Prints a signed decimal integer.
       %i     Equivalent to %d, prints a signed decimal integer.
SPECIFIERS ARRAY
       The specifiers array used in the implementation matches format
       characters with their corresponding handling functions:
       • {'c', print_char}     : Handles character printing
       • {'s', print_string}   : Handles string printing
       • {'%', print_percent}  : Handles percent character printing
       • {'d', print_integer}  : Handles signed integer printing
       • {'i', print_integer}  : Alias for 'd'
RETURN VALUE
       The function returns:
       • The number of characters printed (excluding null termination byte)
       • -1 in case of error (e.g., NULL format or lone '%' at end)
SPECIAL CASE HANDLING
       • Negative numbers are printed correctly using a helper array.
       • If a format specifier is unknown, the '%' and character are printed as-is.
       • Null strings are replaced by "(null)".
EXAMPLES
       Printing a string:
              _printf("Hello, %s!", "world");
       Output:
              Hello, world!
       Printing an integer:
              _printf("Number: %d", -42);
       Output:
              Number: -42
       Mixed printing:
              _printf("Char: %c, String: %s", 'A', "text");
       Output:
              Char: A, String: text
FILES
       • main.h           : Header file with prototypes and struct
       • _printf.c        : Core implementation of the _printf logic
       • specifiers.c     : Static list of supported specifiers
       • handlers.c       : Functions to handle each specifier
       • _putchar.c       : Low-level wrapper around write
       • main.c (example) : Test case examples (not graded)
BUGS
       • No support for width, flags, precision, or length modifiers
       • No support for unsigned, hex, float, or octal specifiers
       • Unknown format specifiers are not handled according to standard printf
AUTHOR
       Developed by the _printf project contributors:
       P-Y74 and Alexiscnl
NOTES
       This project is intended for educational purposes, especially to
       practice variadic functions, structs, and function pointers in C.






