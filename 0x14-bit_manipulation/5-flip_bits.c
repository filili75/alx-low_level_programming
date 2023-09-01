#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int r;
	int counts = 0;
	unsigned long int currents;
	unsigned long int exclusive = n ^ m;

	for (r = 63; r >= 0; r--)
	{
		currents = exclusive >> r;
		if (currents & 1)
			counts++;
	}

	return (counts);
}

