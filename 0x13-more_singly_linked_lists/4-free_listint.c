#include "lists.h"
#include <stdio.h>
/**
 * free_listint - Frees a linked list.
 * @list_head: Pointer to the first node of the list to be freed.
 */
void free_listint(listint_t *list_head)
{
    listint_t *current_node;

    while (list_head)
    {
        current_node = list_head->next;
        free(list_head);
        list_head = current_node;
    }
}

