#include "lists.h"
#include <stdio.h>
/**
 * delete_nodeint_at_index - Deletes a node in a linked list at a certain index.
 * @list_head: Pointer to the pointer of the first element in the list.
 * @index: Index of the node to delete.
 *
 * Return: 1 (Success), or -1 (Failure).
 */
int delete_nodeint_at_index(listint_t **list_head, unsigned int index)
{
	listint_t *current_node = *list_head;
	listint_t *temp_node = NULL;
	unsigned int position = 0;

	/* Check if the list is empty */
	if (*list_head == NULL)
		return (-1);

	/* Handle deletion of the first node (head) */
	if (index == 0)
	{
		*list_head = (*list_head)->next;
		free(current_node);
		return (1);
	}

	/* Traverse the list to find the node before the one to delete */
	while (position < index - 1)
	{
		if (!current_node || !(current_node->next))
			return (-1);
		current_node = current_node->next;
		position++;
	}

	/* Store the node to be deleted and update the pointers */
	temp_node = current_node->next;
	current_node->next = temp_node->next;
	free(temp_node);

	return (1);
}

