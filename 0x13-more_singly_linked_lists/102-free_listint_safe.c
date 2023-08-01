#include "lists.h"

/**
 * free_listint_safe - Frees a linked list safely.
 * @list_head: Pointer to the pointer of the first node in the linked list.
 *
 * Return: Number of elements in the freed list.
 */
#include <stdlib.h>

/* Define the listint_t structure */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/* Safely frees a linked list of integers and returns the number of nodes freed */
size_t free_listint_safe(listint_t **h)
{
    size_t len = 0;         // Variable to store the number of nodes freed
    int diff;               // Variable to calculate the difference between node addresses
    listint_t *temp;        // Temporary pointer to hold the next node's address during deletion

    // Check if the input list or the first node is NULL
    if (!h || !*h)
        return (0);

    // Loop through the linked list and free each node one by one
    while (*h)
    {
        diff = *h - (*h)->next; // Calculate the difference between the current node address and the next node address
        if (diff > 0)
        {
            // If the difference is positive, it means there are more nodes ahead, proceed with deletion
            temp = (*h)->next;  // Store the address of the next node
            free(*h);           // Free the current node
            *h = temp;          // Move to the next node
            len++;              // Increment the counter of freed nodes
        }
        else
        {
            
            free(*h);           // Free the current node
            *h = NULL;          // Set the head pointer to NULL, breaking the loop
            len++;              // Increment the counter of freed nodes
            break;              // Exit the loop
        }
    }

    *h = NULL;          // After freeing all nodes, set the head pointer to NULL to prevent dangling pointer

    return (len);       // Return the number of nodes freed
}

