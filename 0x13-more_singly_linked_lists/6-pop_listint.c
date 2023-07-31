#include "lists.h"

/**
 * pop_listint - Deletes the head node of a linked list.
 * @list_head: Pointer to the pointer of the first element in the linked list.
 *
 * Return: The data inside the element that was deleted, or 0 if the list is empty.
 */
int pop_listint(listint_t **list_head)
{
    listint_t *temp;
    int data;

    /* Check if the input pointer is NULL or if the list is empty */
    if (!list_head || !*list_head)
        return (0);

    /* Store the data of the head node to be deleted */
    data = (*list_head)->n;
    /* Move the head to the next node */
    temp = (*list_head)->next;
    /* Free the current head node */
    free(*list_head);
    /* Update the head to point to the next node */
    *list_head = temp;

    /* Return the data of the deleted head node */
    return (data);
}

