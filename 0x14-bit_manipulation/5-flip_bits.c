#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * To get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{

	int e, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (e = 63; e >= 0; e--)
	{
		current = exclusive >> e;
		if (current & 1)
			count++;
	}

	return (count);
}




