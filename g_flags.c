#include "main.h"

/**
 * g_flags - determines active flags
 * @format: Formatted string in which to print the arguments
 * @i: parameter used
 * Return: Flags
 */

int g_flags(const char *format, int *i)
{
	/* F(-)=1, F(+)=2, F(0)=4, F(#)=8, F('')=16 */
	int flags = 0;
	int a, member_i;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (member_i = *i + 1; format[member_i] != '\0'; member_i++)
	{
		for (a = 0; FLAGS_CH[a] != '\0'; a++)
			if (format[member_i] == FLAGS_CH[a])
			{
				flags |= FLAGS_ARR[a];
				break;
			}
		if (FLAGS_CH[a] == 0)
			break;
	}

	*i = member_i - 1;

	return (flags);
}
