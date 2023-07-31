#include "lists.h"
#include <stdio.h>

/**
 * count_loop_nodes - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @list_head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t count_loop_nodes(const listint_t *list_head)
{
    const listint_t *slow, *fast;
    size_t nodes_count = 1; // At least one node, head node

    if (list_head == NULL || list_head->next == NULL)
        return (0); // Empty list or single node, not looped

    slow = list_head->next;
    fast = (list_head->next)->next;

    // Detect a loop in the list
    while (fast)
    {
        if (slow == fast) // Loop detected
        {
            // Count the number of nodes in the loop
            slow = list_head;
            while (slow != fast)
            {
                nodes_count++;
                slow = slow->next;
                fast = fast->next;
            }

            // Count the remaining nodes after the loop
            slow = slow->next;
            while (slow != fast)
            {
                nodes_count++;
                slow = slow->next;
            }

            return (nodes_count);
        }

        slow = slow->next;
        fast = (fast->next)->next;
    }

    return (0); // List is not looped
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @list_head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *list_head)
{
    size_t nodes_count, index = 0;

    nodes_count = count_loop_nodes(list_head);

    if (nodes_count == 0) // Not a looped list
    {
        for (; list_head != NULL; nodes_count++)
        {
            printf("[%p] %d\n", (void *)list_head, list_head->n);
            list_head = list_head->next;
        }
    }
    else // Loop detected in the list
    {
        for (index = 0; index < nodes_count; index++)
        {
            printf("[%p] %d\n", (void *)list_head, list_head->n);
            list_head = list_head->next;
        }

        /* Print the node where the loop occurs */
        printf("-> [%p] %d\n", (void *)list_head, list_head->n);
    }

    return (nodes_count);
}

