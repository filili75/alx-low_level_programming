#include <stdio.h>

void print_before_main(void) __attribute__ ((constructor));

/**
 * print_before_main - This function is executed automatically before the main function.
 *
 * Description: This function prints a sentence to the standard output
 *              before the main function is executed.
 */
void print_before_main(void)
{
    printf("You're beat! and yet, you must allow,\n");
    printf("I bore my house upon my back!\n");
}
