#include "main.h"

/**
 * get_endianness - is a function that checks the endianness.
 *
 * Return: return 1 if little endian and 0 for big endian.
 */

int get_endianness(void)
{
	unsigned int x;
	char *c;

	x = 1;
	c = (char *) &x;

	return ((int)*c);
}
