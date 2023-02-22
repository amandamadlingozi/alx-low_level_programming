#include "main.h"

/**
 * print_alphabet_x10 - print alphabet
 *
 * Return: Always 0.
 */
void print_alphabet_x10(void)
{
int x;
int count;


count = 0;
while (count < 10)
{
for (x = 'a' ; x <= 'z'; x++)
{
_putchar(x);
}

count++;
_putchar('\n');
}


}
