#include "lists.h"

/**
 * get_nodeint_at_index - Returns the node at a certain index in a linked list.
 * @list_head: Pointer to the first node in the linked list.
 * @index: Index of the node to return.
 *
 * Return: Pointer to the node at the specified index, or NULL if not found.
 */
listint_t *get_nodeint_at_index(listint_t *list_head, unsigned int index)
{
    unsigned int current_index = 0;
    listint_t *current_node = list_head;

    /* Traverse the linked list until the specified index is found or the end of the list is reached */
    while (current_node && current_index < index)
    {
        current_node = current_node->next;
        current_index++;
    }

    /* Return the node at the specified index, or NULL if the index is beyond the end of the list */
    return (current_node ? current_node : NULL);
}

