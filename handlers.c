#include "main.h"

/**
 * handle_ink_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags: Determines active flags.
 * @width: A width specifier
 * @precision: A precision specifier
 * @size: A size specifier
 *
 * Return: Number of chars printed
 */
int hndle_write_char(char c, char buffer[], int flags,
		int width, int precision, int size)
{ 
	int a = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[a++] = c;
	buffer[a] = '\0';
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (a = 0; a < width - 1; a++)
			buffer[BUFF_SIZE - a - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - a - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - a - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_number - Writes a string
 * @is_negative: Lista of arguments
 * @cr: char types
 * @buffer: Buffer array to handle print
 * @flags: Determines active flags
 * @width: A width specifier
 * @precision: A precision specifier
 * @size: A size specifier
 *
 * Return: Number of chars printed
 */
int write_number(int is_negative, int cr, char buffer[], int flags,
		int width, int precision, int size)
{
	int length = BUFF_SIZE - cr - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_numb(cr, buffer, flags, width, precision,
		length, padd, extra_ch));
}

/**
 * write_num - Writes a number using a bufffer
 * @cr: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int write_num(int cr, char buffer[], int flags, int width,
		int prec, int length, char padd, char extra_c)
{
	int a, padd_start = 1;

	if (prec == 0 && cr == BUFF_SIZE - 2 && buffer[cr] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && cr == BUFF_SIZE - 2 && buffer[cr] == '0')
		buffer[cr] = padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--cr] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (a = 1; a < width - length + 1; a++)
			buffer[a] = padd;
		buffer[a] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				buffer[--cr] = extra_c;
			return (write(1, &buffer[cr], length) + write(1, &buffer[1], a - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				buffer[--cr] = extra_c;
			return (write(1, &buffer[1], a - 1) + write(1, &buffer[cr], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], a - padd_start) +
				write(1, &buffer[cr], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--cr] = extra_c;
	return (write(1, &buffer[cr], length));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @cr: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of printed chars.
 */
int write_unsgnd(int is_negative, int cr, char buffer[],
		int flags, int width, int precision, int size)
{
	/* The number is stored at the bufer's right and starts at position a */
	int length = BUFF_SIZE - cr - 1, a = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && cr == BUFF_SIZE - 2 && buffer[cr] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--cr] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (a = 0; a < width - length; a++)
			buffer[a] = padd;

		buffer[a] = '\0';

		if (flags & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[cr], length) + write(1, &buffer[0], a));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], a) + write(1, &buffer[cr], length));
		}
	}

	return (write(1, &buffer[cr], length));
}

/**
 * write_pointer - Writes a memory address
 * @buffer: Arrays of chars
 * @cr: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Wwidth specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int cr, int length, int width,
		int flags, char padd, char extra_c, int padd_start)
{
	int a;

	if (width > length)
	{
		for (a = 3; a < width - length + 3; a++)
			buffer[a] = padd;
		buffer[a] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--cr] = 'x';
			buffer[--cr] = '0';
			if (extra_c)
				buffer[--cr] = extra_c;
			return (write(1, &buffer[cr], length) + write(1, &buffer[3], a - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buffer */
		{
			buffer[--cr] = 'x';
			buffer[--cr] = '0';
			if (extra_c)
				buffer[--cr] = extra_c;
			return (write(1, &buffer[3], a - 3) + write(1, &buffer[cr], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], a - padd_start) +
				write(1, &buffer[cr], length - (1 - padd_start) - 2));
		}
	}
	buffer[--cr] = 'x';
	buffer[--cr] = '0';
	if (extra_c)
		buffer[--cr] = extra_c;
	return (write(1, &buffer[cr], BUFF_SIZE - cr - 1));
}
