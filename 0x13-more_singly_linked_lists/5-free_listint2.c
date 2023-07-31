#include "lists.h"
#include <stdio.h>
/**
 * free_listint2 - Frees a linked list and sets head to NULL.
 * @head: Pointer to the pointer of the listint_t list to be freed.
 */
void free_listint2(listint_t **head)
{
    listint_t *temp;

    /* Check if the input pointer is NULL */
    if (head == NULL)
        return;

    /* Traverse the linked list and free each node */
    while (*head)
    {
        /* Store the next node in the list */
        temp = (*head)->next;
        /* Free the current node */
        free(*head);
        /* Move the head to the next node */
        *head = temp;
    }

    /* Set the head pointer to NULL, indicating an empty list */
    *head = NULL;
}

