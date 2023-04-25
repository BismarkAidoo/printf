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

	````
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
	````

- 3. What one has not experienced, one will never understand in print

	* Handle the following conversion specifiers:
		`u`
		`o`
		`x`
		`X`

- 4. Nothing in fine print is ever good news
	
	* Use a local buffer of 1024 chars in order to call write as little as possible.

- 5. My weakness is wearing too much leopard print

	* Handle the following custom conversion specifier:

		- `S` : prints the string.
		- Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: `\x`, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)
	````
	alex@ubuntu:~/c/printf$ cat main.c
	#include "main.h"

	/**
 	* main - Entry point
 	*
 	* Return: Always 0
 	*/
	int main(void)
	{
    	_printf("%S\n", "Best\nSchool");
    	return (0);
	}
	alex@ubuntu:~/c/printf$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 main.c
	alex@ubuntu:~/c/printf$ ./a.out
	Best\x0ASchool
	alex@ubuntu:~/c/printf$
	````

- 6. How is the world ruled and led to war? Diplomats lie to journalists and believe these lies when they see them in print

	* Handle the following conversion specifier: `p`.

- 7. The big print gives and the small print takes away

	* Handle the following flag characters for non-custom conversion specifiers:

		`+`
		space
		`#`

- 8. Sarcasm is lost in print

	* Handle the following length modifiers for non-custom conversion specifiers:

		`l`
		`h`
		- Conversion specifiers to handle: `d`, `i`, `u`, `o`, `x`, `X`

- 9. Print some money and give it to us for the rain forests

- 10. The negative is the equivalent of the composer's score, and the print the performance

- 11. It's depressing when you're still around and your albums are out of print

- 12. Every time that I wanted to give up, if I saw an interesting textile, print what ever, suddenly I would see a collection

- 13. Print is the sharpest and the strongest weapon of our party

	* `r` : prints the reversed string

- 14. The flood of print has turned reading into a process of gulping rather than savoring

	* `R`: prints the rot13'ed string

- 15. *

All the above options work well together.

## Acknowledgements
The `printf` function emulates functionality of the C standard library function `printf`. This README borrows from the Linux man page printf(3).

This program was written as part of the curriculum for ALX School. ALX School is a virtual-based full stack software engineering program that prepares students for careers in the tech industry using project-based peer learning.

