#include "main.h"

/**
 * get_endianness - check if a machine is little or big endian
 * Return: 0 for big, 1 for litle.
 */
int get_endianness(void)
{
	unsigned int r = 1;
	char *s = (char *) &r;

	return (*s);
}

