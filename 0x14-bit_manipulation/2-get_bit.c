#include "main.h"

/**
 * get_bit - return the value of a bit at an index in a decimal number.
 * @n: number to search.
 * @index: index of the bits
 *
 * Return: values of the bits
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_valu;

	if (index > 63)
		return (-1);

	bit_valu = (n >> index) & 1;

	return (bit_valu);
}

