#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Frees a linked list.
 * @head: Pointer to the list_t list to be freed.
 *
 * Description: This function iterates through the linked list and frees each node.
 *              It also frees the memory allocated for the string within each node.
 */
void free_list(list_t *head)
{
    list_t *temp;

    while (head)
    {
        temp = head->next;   /* Store the next node before freeing the current node */
        free(head->str);     /* Free the memory allocated for the string */
        free(head);          /* Free the memory allocated for the current node */
        head = temp;         /* Move to the next node */
    }
}
