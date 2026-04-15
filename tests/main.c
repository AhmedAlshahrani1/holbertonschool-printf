#include <stdio.h>
#include "../main.h"

/**
 * main - Entry point for testing _printf
 *
 * Return: Always 0
 */
int main(void)
{
    int len1, len2;

    len1 = _printf("Let's try our printf!\n");
    len2 = printf("Let's try our printf!\n");
    printf("Our len: %d | Real len: %d\n\n", len1, len2);

    len1 = _printf("Character: %c\n", 'H');
    len2 = printf("Character: %c\n", 'H');
    printf("Our len: %d | Real len: %d\n\n", len1, len2);

    len1 = _printf("String: %s, Percent: %%\n", "Holberton");
    len2 = printf("String: %s, Percent: %%\n", "Holberton");
    printf("Our len: %d | Real len: %d\n", len1, len2);

    return (0);
}
