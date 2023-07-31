#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: linked list to search for.
 *
 * Return: The address of the node where the loop starts, or NULL if there is no loop.
 */

listint_t *find_listint_loop(listint_t *head)
{
        listint_t *slow = head; // Tortoise pointer
        listint_t *fast = head; // Hare pointer

        if (!head)
                return (NULL); // No loop in an empty list

        while (slow && fast && fast->next)
        {
                fast = fast->next->next; // Hare moves two steps at a time
                slow = slow->next; // Tortoise moves one step at a time

                // Check if the pointers meet (loop detected)
                if (fast == slow)
                {
                        // Reset one of the pointers and move both at the same pace
                        slow = head; // Reset the tortoise to the head
                        while (slow != fast)
                        {
                                slow = slow->next;
                                fast = fast->next;
                        }

                        // The pointers meet at the loop starting node
                        return (fast);
                }
        }

        return (NULL); // No loop detected
}

