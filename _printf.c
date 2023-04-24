#include "main.h"

void clear_up(va_list args, buffer_t *output);
int read_printf(const char *format, va_list args, buffer_t *output);
int _printf(const char *format, ...);

/**
 * clear_up - Peforms tidying operations for _printf.
 * @args: variable list of arguments provided to _printf.
 * @output: A buffer_t struct.
 */
void clear_up(va_list args, buffer_t *output)
{
	va_end(args);
	write(1, output->start, output->len);
	free_buffer(output);
}

/**
 * read_printf - a function reads through the format string for _printf.
 * @format: Character string to print - may contain directives.
 * @output: A buffer_t struct containing a temporal data.
 * @args: A variable list of arguments.
 *
 * Return: The number of characters stored to output.
 */
int read_printf(const char *format, va_list args, buffer_t *output)
{
	int a, width, p, r = 0;
	char tmp;
	unsigned char flags, len;
	unsigned int (*form)(va_list, buffer_t *,
			unsigned char, int, int, unsigned char);

	for (a = 0; *(format + a); a++)
	{
		len = 0;
		if (*(format + a) == '%')
		{
			tmp = 0;
			flags = handle_flags(format + a + 1, &tmp);
			width = handle_width(args, format + a + tmp + 1, &tmp);
			p = handle_precision(args, format + a + tmp + 1,
					&tmp);
			len = handle_length(format + a + tmp + 1, &tmp);

			form = handle_specifiers(format + a + tmp + 1);
			if (form != NULL)
			{
				a += tmp + 1;
				r += form(args, output, flags, width, p, len);
				continue;
			}
			else if (*(format + a + tmp + 1) == '\0')
			{
				r = -1;
				break;
			}
		}
		r += _memcpy(output, (format + a), 1);
		a += (len != 0) ? 1 : 0;
	}
	clear_up(args, output);
	return (r);
}

/**
 * _printf - A function that outputs a formatted string to output stream.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	buffer_t *output;
	va_list args;
	int r;

	if (format == NULL)
		return (-1);
	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(args, format);

	r = read_printf(format, args, output);

	return (r);
}
