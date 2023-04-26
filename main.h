#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

/* Flags Modifier Macros */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* Length Modifier Macros */
#define S_SHORT 1
#define S_LONG 2

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *cr, va_list args, char buffer[],
		int flags, int width, int precision, int size);


/* Functions to display chars and strings */
int display_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int display_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int display_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to display numbers */
int display_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int display_bin(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int display_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int display_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int display_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int display_hex_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int display_hex(va_list types, char go_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size);

/* Function to display non printable characters */
int display_non_printable(va_list types, char buffer[], int flags,
		int width, int precision, int size);

/* Function to display memory address */
int display_pointer(va_list types, char buffer[], int flags,
		int width, int precision, int size);

/***** Handlers *****/
int g_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list args);
int precision(const char *format, int *i, va_list args);
int size(const char *format, int *i);

/*Function to display string in reverse*/
int display_reverse(va_list types, char buffer[], int flags,
		int width, int precision, int size);

/*Function to display a string in rot 13*/
int display_r13string(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size);
int write_number(int is_positive, int index, char buffer[], 
		int flags, int width, int precision, int size);
int write_numb(int cr, char bff[], int flags, int width, int precision,
		int length, char padd, char extra_c);
int write_pointer(char buffer[], int cr, int length,
		int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int cr, char buffer[],
		int flags, int width, int precision, int size);

/********* Utils ***********/
int is_printable(char);
int affix_hex_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);


#endif
