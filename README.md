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
		printf("Hello, Mark & Ann");
		
		return (0);
	}

Compilation:

	$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o test_file

Output:
	$ ./test_file
	Hello, Mark & Ann                                                                                                   
	$


## Authors
- Bismark Aidoo
- Antoinette Mensah

## Acknowledgements
The `printf` function emulates functionality of the C standard library function `printf`. This README borrows from the Linux man page printf(3).

This program was written as part of the curriculum for ALX School. ALX School is a virtual-based full stack software engineering program that prepares students for careers in the tech industry using project-based peer learning.

