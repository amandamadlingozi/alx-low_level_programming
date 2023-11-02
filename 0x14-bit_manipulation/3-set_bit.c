#include "main.h"

/**
 * set_bit - sets value of a bit to 1 at given index
 * @n: pointer
 * @index: index of bit
 *
 * Return: 1 if success, -1 if failure
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int m;

	if (index > 63)
		return (-1);

	m = 1 << index;
	*n = (*n | m);

	return (1);
}
