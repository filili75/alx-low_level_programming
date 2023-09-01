#include "main.h"

/**
 * print_binary - prints the binary equivalent of decimal number.
 * @n: number to print in binary of the function.
 */
void print_binary(unsigned long int n)
{
	int s;
	int counts = 0;
	unsigned long int currents;

	for (s = 63; s >= 0; s--)
	{
		currents = n >> s;

		if (currents & 1)
		{
			_putchar('1');
			counts++;
		}
		else if (counts)
			_putchar('0');
	}
	if (!counts)
		_putchar('0');
}

