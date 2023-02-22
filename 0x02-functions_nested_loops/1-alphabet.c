#include <stdio.h>
#include <main.h>
/**
 * print_alphabet - a function that prints the alphabet, in lowercase
 * Return: 0 (Success)
 */
void print_alphabet(void)
{
	int n;

	for (n = 'a'; n <= 'z'; n++)
	{
		putchar(n);
	}
	putchar('\n');
}
