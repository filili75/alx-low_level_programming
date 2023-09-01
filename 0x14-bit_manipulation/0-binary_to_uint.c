#include "main.h"

/**
 * binary_to_uint - convert a binary number to unsigned int
 * @b: string pointing to a binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int f;
	unsigned int des_valu = 0;

	if (!b)
		return (0);

	for (f = 0; b[f]; f++)
	{
		if (b[f] < '0' || b[f] > '1')
			return (0);
		des_valu = 2 * des_valu + (b[f] - '0');
	}

	return (des_valu);
}

