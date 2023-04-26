#include "main.h"


/**
 * display_char - Print characters
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: determines active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int display_char(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision,
				size));
}

/**
 * display_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: determines active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int display_string(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int length = 0, a;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "     ";
	}
	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (a = width - length; a > 0; a--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (a = width - length; a > 0; a--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}

/**
 * display_precent - display a percent sign
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: determines active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int display_percent(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * display_int -displays int
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: determines active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int display_int(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int a = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int numb;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	numb = (unsigned long int)n;

	if (n < 0)
	{
		numb = (unsigned long int) ((-1) * n);
		is_negative = 1;
	}
	while (numb > 0)
	{
		buffer[a--] = (numb % 10) + '0';
		numb /= 10;
	}

	a++;

	return (write_number(is_negative, a, buffer, flags, width, precision, size));
}

/**
 * display_bin - display an unsigned number
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: determines active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed
 */

int display_bin(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	unsigned int n, m, a, sum;
	unsigned int arr[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	arr[0] = n / m;

	for (a = 1; a < 32; a++)
	{
		m /= 2;
		arr[a] = (n / m) % 2;
	}
	for (a = 0, sum = 0, count = 0; a < 32; a++)
	{
		sum += arr[a];
		if (sum || a == 31)
		{
			char z = '0' + arr[a];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
