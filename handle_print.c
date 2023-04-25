#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @args: List of arguments to be printed.
 * @cr: current integer.
 * @width: get width.
 * @flags: Determines active flags
 * @buffer: buffer array to handle print.
 * @size: size specifier
 * @precision: Precision specification
 * Return: 1 or 2;
 */

int handle_print(const char *fmt, int *cr, va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int a, unknown_len = 0, display_chars = -1;
	
	fmt_t fmt_types[] = {
		{'c', display_char}, {'s', display_string}, {'%', display_percent},
		{'i', display_int}, {'d', display_int}, {'b', display_bin},
		{'u', display_unsigned}, {'o', display_octal}, {'x', display_hexadecimal},
		{'X', display_hex_upper}, {'p', display_pointer}, {'S', display_non_printable},
		{'r', display_reverse}, {'R', display_r13string}, {'\0', NULL}
	};

	for (a = 0; fmt_types[a].fmt != '\0'; a++)
		if (fmt[*cr] == fmt_types[a].fmt)
			return (fmt_types[a].fn(args, buffer, flags, width, precision, size));
	if (fmt_types[a].fmt == '\0')
	{
		if (fmt[*cr] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (fmt[*cr - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*cr);
			while (fmt[*cr] != ' ' && fmt[*cr] != '%')
				--(*cr);
			if (fmt[*cr] == ' ')
				--(*cr);
			return (1);
		}
		unknown_len += write(1, &fmt[*cr], 1);
		return (unknown_len);
	}
	return (display_chars);
}
