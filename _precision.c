#include "main.h"

/**
 * _precision - determines the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed
 * @args: list of arguments
 *
 * Return: P
 */

int _precision(const char *format, int *i, va_list args)
{
	int member_i = *i + 1;
	int p = -1;

	if (format[member_i] != '.')
		return (p);
	p = 0;

	for (member_i += 1; format[member_i] != '\0'; member_i++)
	{
		if (_digit(format[member_i]))
		{
			p *= 10;
			p += format[member_i] - '0';
		}
		else if (format[member_i] == '*')
		{
			member_i++;
			p = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = member_i - 1;

	return (p);
}
