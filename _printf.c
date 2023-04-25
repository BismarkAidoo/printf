#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	int a, display = 0, display_chars = 0;
	int f, w, p, s, buff_ind = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buffer[buff_ind++] = format[a];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[a], 1);*/
			display_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			f = g_flags(format, &a);
			w = get_width(format, &a, args);
			p = precision(format, &a, args);
			s = size(format, &a);
			++a;
			display = handle_print(format, &a, args, buffer, f, w, p, s);
			if (display == -1)
				return (-1);
			display_chars += display;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(args);

	return (display_chars);
}

/**
 * print_buffer - display the values of the buffer if it exist.
 * @buff_ind: Index at which to add next char, represents the length.
 * @buffer: Array of chars
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
