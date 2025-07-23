# Project : _Printf Function

This project replicates the standard `printf` function using variadic functions in C.  
The objective is to manipulate structures, function pointers, and argument parsing dynamically.
---

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Supported Format Specifiers](#supported-format-specifiers)
- [Project Structure](#project-structure)
- [How to Compile](#how-to-compile)
- [Manual Page](#manual-page)
- [Manual Page](#manual-page)
- [Usage Examples](#usage-examples)
- [Limitations](#limitations)
- [Author](#author)

---

## Requirements

- All files will be compiled on Ubuntu 20.04 LTS with :

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
```
- All files must end with a new line.
- A README.md at the root of the project.
- The code must follow the Betty coding style.
- No more than 5 functions per file.
- Global variable are not allowed.
- The prototypes of all functions must be included in a header file named main.h.
- All header files must be include guarded.

---
## Features

- Support a subset of format specifiers (`%c`, `%s`, `%d`, `%i`, and `%%`)
- Clean modular structure using function pointers and `struct` dispatch
- Graceful handling of null strings
- Simplified mimic of the standard printf behavior

---

## Supported Format Specifiers

| Specifier | Description                   |
|-----------|-------------------------------|
| `%c`      | Character                     |
| `%s`      | String                        |
| `%%`      | Literal percent sign          |
| `%d`      | Signed decimal integer        |
| `%i`      | Signed decimal integer        |

---

## Project Structure

| File               | Description |
|--------------------|-------------|
| `main.h`           | Header file with declarations and `type_specifier` struct |
| `_printf.c`        | Core implementation of `_printf` |
| `specifiers.c`     | Returns array of supported specifiers |
| `handlers.c`       | Individual handlers for each format specifier |
| `_putchar.c`       | Wrapper for `write` to output characters |
| `main.c`           | Sample test cases |

---

## How to Compile
## How to Compile

You can compile all source files using `gcc`:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
```
---

## Manual page

To open the manual, use the following command : 
```bash 
cat man_3_printf
```
---

## Usage Examples

```bash
_printf("Let's try to printf a simple sentence.\n");
// Output: Let's try to printf a simple sentence.

_printf("Length:[%d, %i]\n", 42, 42);
// Output: Length:[42, 42]

_printf("Character:[%c]\n", 'H');
// Output: Character:[H]

_printf("String:[%s]\n", "I am a string !");
// Output: String:[I am a string !]

_printf("Percent:[%%]\n");
// Output: Percent:[%]
```
---

## Limitations

Does not support width, precision, flags, or length modifiers

Undefined behavior for unsupported format specifiers (prints %x if %x is unknown)

No float or hex support (%f, %x, %X, %u, etc.)

---
