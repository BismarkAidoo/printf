#include "main.h"

/**
 * get_width - determines the width of values to be printed
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @args: list of arguments.
 *
 * Return: width.
 */

int get_width(const char *format, int *i, va_list args)
{
	/* li_arg for current index in pointer i */
	int li_arg;
	int w = 0;

	for (li_arg = *i + 1; format[li_arg] != '\0'; li_arg++)
	{
		if (is_digit(format[li_arg]))
		{
			w *= 10;
			w += format[li_arg] - '0';
		}
		else if (format[li_arg] == '*')
		{
			li_arg++;
			w = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = li_arg - 1;

	return (w);
}
