#include "lists.h"

/**
 * print_listint-Prints all the elements of a listint_t list.
 * @h: Pointer to the head of the lists.
 *
 * return: The number of nodes in the lists.
 */
size_t print_listint(const listint_t *h)
{
    const listint_t *current = h;
    size_t num_nodes = 0; // Changed the variable name from "count" to "num_nodes"

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
        num_nodes++; // Changed the increment variable to "num_nodes"
    }

    return num_nodes; // Changed the return variable to "num_nodes"
}

