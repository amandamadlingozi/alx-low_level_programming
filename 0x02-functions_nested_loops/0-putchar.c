#include <main.h>
/**
 * main - Program prints putchar
 * Return: 0 (Success)
 */
int main(void)
{
	int i;
	char p[] = "_putchar";

	for (i = 0; i < 9; i++)
		{
		putchar(p[i]);
		}
		putchar('\n');
	return (0);
}
