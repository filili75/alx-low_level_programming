#include "lists.h"

/**
 * reverse_listint - Reverses a linked list.
 * @list_head: Pointer to the pointer of the first node in the list.
 *
 * Return: Pointer to the first node in the new reversed list.
 */
listint_t *reverse_listint(listint_t **list_head)
{
	listint_t *previous = NULL;
	listint_t *next_node = NULL;

	/* Traverse the list and reverse the next pointers of each node */
	while (*list_head)
	{
		next_node = (*list_head)->next;
		(*list_head)->next = previous;
		previous = *list_head;
		*list_head = next_node;
	}

	/* Set the head pointer to point to the new first node (previously last node) */
	*list_head = previous;

	return (*list_head);
}

