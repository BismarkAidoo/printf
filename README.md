# printf
The program is pseudo-recreation of the C standard library function, `printf`.

## Dependencies
The `printf` function was coded on an Ubuntu 20.04 LTS with `gcc` version 9.4.0 using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`.

## Usage
To use the `printf` function, assuming the above dependencies have been installed, all `.c` files in the repository and include the header `main.h` with any main function will be compiled using the illustration below;

Example `main.c`:
	#include "main.h"
	
	int main(void)
	{
		printf("Team-Work makes the Dream Work!");
		
		return (0);
	}

Compilation:

	$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o test_file

Output:

```
$ ./test_file
Team-Work makes the Dream Work!
$ 
```
                                                                         

## Authors
- Bismark Aidoo
- Antoinette Mensah

## Tasks
- 0. I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life

	* Write a function that produces output according to a format.

		- Prototype: `int _printf(const char *format, ...);`
		- Returns: the number of characters printed (excluding the null byte used to end output to strings)
		- write output to stdout, the standard output stream
		- `format` is a character string. The format string is composed of zero or more directives. See `man 3 printf` for more detail. You need to handle the following conversion specifiers:
			`c`
			`s`
			`%`

- 1. Education is when you read the fine print. Experience is what you get if you don't

	* Handle the following conversion specifiers:

		`d`
		`i` 

- 2. With a face like mine, I do better in print

	* Handle the following custom conversion specifiers:

		`b`: the unsigned int argument is converted to binary


	alex@ubuntu:~/c/printf$ cat main.c
	#include "main.h"

	/**
 	* main - Entry point
 	*
 	* Return: Always 0
 	*/
	int main(void)
	{	
    	_printf("%b\n", 98);
    	return (0);
	}
	alex@ubuntu:~/c/printf$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 main.c
	alex@ubuntu:~/c/printf$ ./a.out
	1100010
	alex@ubuntu:~/c/printf$


- 3. What one has not experienced, one will never understand in print

	* Handle the following conversion specifiers:
		`u`
		`o`
		`x`
		`X`

## Acknowledgements
The `printf` function emulates functionality of the C standard library function `printf`. This README borrows from the Linux man page printf(3).

This program was written as part of the curriculum for ALX School. ALX School is a virtual-based full stack software engineering program that prepares students for careers in the tech industry using project-based peer learning.

