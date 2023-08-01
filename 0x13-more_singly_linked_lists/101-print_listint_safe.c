#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t looped_listint_safe(const listint_t *head);

/**
 * looped_listint_len - Counts the number of unique nodes
 *                      in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 *         Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
    const listint_t *tortoise, *hare;
    size_t nodes = 1; // Initialize the count of nodes to 1 (at least one node, the head node)

    if (head == NULL || head->next == NULL)
        return (0); // If the list is empty or contains only one node, it is not looped.

    // Initialize the tortoise and hare pointers.
    tortoise = head->next; // Tortoise moves one step.
    hare = (head->next)->next; // Hare moves two steps.

    // Detect a loop in the list using the Floyd's Cycle Detection algorithm.
    while (hare)
    {
        if (tortoise == hare) // Loop detected as tortoise and hare pointers meet.
        {
            tortoise = head; // Reset the tortoise to the head.

            // Count the number of nodes in the loop.
            while (tortoise != hare)
            {
                nodes++;
                tortoise = tortoise->next;
                hare = hare->next;
            }

            // Count the remaining nodes after the loop.
            tortoise = tortoise->next;
            while (tortoise != hare)
            {
                nodes++;
                tortoise = tortoise->next;
            }

            return (nodes); // Return the total number of nodes in the list.
        }

        // Move tortoise one step and hare two steps.
        tortoise = tortoise->next;
        hare = (hare->next)->next;
    }

    return (0); // List is not looped, return 0.
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t nodes, index = 0;

    // Count the number of nodes in the list, handling loops if any.
    nodes = looped_listint_len(head);

    if (nodes == 0) // If the list is not looped.
    {
        // Print each node in the list and update the count of nodes.
        for (; head != NULL; nodes++)
        {
            printf("[%p] %d\n", (void *)head, head->n);
            head = head->next;
        }
    }
    else // If the list is looped.
    {
        // Print the nodes before the loop starts and update the index count
        for (index = 0; index < nodes; index++)
        {
            printf("[%p] %d\n", (void *)head, head->n);
            head = head->next;
        }

        // Print the node where the loop occurs.
        printf("-> [%p] %d\n", (void *)head, head->n);
    }

    return (nodes); // Return the total number of nodes in the list.
}

