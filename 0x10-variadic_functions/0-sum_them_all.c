#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all Returns the sum of all its paramter
 * @n: The number  paramters passed to the functions
 * @...:variable number of paramters to calculate the sum 
 *
 * Return: If n == 0 - 0
 * Otherwise sum of all parameters
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	 int s=0 , i = n;
          if (!n)
		  return (0);
	va_start(ap, n);

	while (i--)
		s += va_arg(ap, int);

	va_end(ap);

	return (s);
}

