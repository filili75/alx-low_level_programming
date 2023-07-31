#include "lists.h"

/**
 * free_listint_safe - Frees a linked list safely.
 * @list_head: Pointer to the pointer of the first node in the linked list.
 *
 * Return: Number of elements in the freed list.
 */
size_t free_listint_safe(listint_t **list_head)
{
	size_t elements_freed = 0;
	int diff;
	listint_t *temp_node;

	if (!list_head || !*list_head)
		return (0);

	while (*list_head)
	{
		diff = *list_head - (*list_head)->next;

		// If the difference is greater than 0, the list is not looped
		if (diff > 0)
		{
			temp_node = (*list_head)->next;
			free(*list_head);
			*list_head = temp_node;
			elements_freed++;
		}
		else
		{
			// If the difference is not greater than 0, the list is looped
			free(*list_head);
			*list_head = NULL;
			elements_freed++;
			break;
		}
	}

	// Set the head pointer to NULL after freeing all elements
	*list_head = NULL;

	return (elements_freed);
}

