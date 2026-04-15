# _printf

## Description
This project is a custom implementation of the standard C library function `printf`. It writes output to `stdout` (the standard output stream) according to a specified format. This project was built to understand variadic functions and basic string parsing in C.

Currently, this custom `_printf` function handles the following conversion specifiers:
* `%c`: Prints a single character.
* `%s`: Prints a string of characters.
* `%%`: Prints a literal percent sign.
* `%d`: Prints a decimal (base 10) integer.
* `%i`: Prints an integer (base 10).

**Note:** This implementation does not reproduce the buffer handling of the C library `printf` function, nor does it handle flag characters, field width, precision, or length modifiers.

## Requirements
* Operating System: Ubuntu 20.04 LTS
* Compiler: `gcc` using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
* Style Guidelines: Code strictly follows the **Betty style**.
* Editors allowed: `vi`, `vim`, `emacs`
* No global variables are used.
* Maximum of 5 functions per file.
* Header files are properly include guarded.

## Installation
Clone the repository to your local machine:
```bash
git clone https://github.com/AhmedAlshahrani1/holbertonschool-printf.git
cd holbertonschool-printf

Testing

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c tests/main.c -o test_printf
./test_printf

Examples

#include "main.h"

int main(void)
{
    int count;
    
    count = _printf("Character: %c\n", 'H');
    _printf("String: %s\n", "Hello World");
    _printf("Integer: %d\n", 1024);
    _printf("Characters printed: %d\n", count);
    
    return (0);
}

Authors
Ahmed 
Dana
