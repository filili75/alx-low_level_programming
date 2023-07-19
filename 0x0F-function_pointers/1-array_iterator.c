#include "function_pointers.h"

#include <stdio.h>

/**

 * array_iterator-Prints each array elem on a new

 * @array: Array

 * @size: How many elem to printS

 * @action: pointers   to print in regular or hex

 * Return: Void

 */

void array_iterator(int *array, size_t size, void (*action)(int))

{

        unsigned int i;


        if (array == NULL || action == NULL)

                return;


        for (i = 0; i < size; i++)

        {

                action(array[i]);

        }

}
