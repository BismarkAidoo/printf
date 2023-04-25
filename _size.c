#include "main.h"

/**
 * size -Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed
 *
 * Return: Precision
 */

int _size(const char *format, int *i)
{
	int member_i = *i + 1;
	int size = 0;

	if (format[member_i] == 'l')
		size = S_LONG;
	else if (format[member_i] == 'h')
		size = S_SHORT;
	if (size == 0)

		*i = member_i - 1;
	else
		*i = member_i;

	return (size);
}
