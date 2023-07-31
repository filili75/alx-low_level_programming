#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure for alx project
 */
typedef struct listint_s
{
    int n;                    /* Integer data stored in the node */
    struct listint_s *next;   
} listint_t;

/* Function prototypes */

/* Print the elements of the linked lists */
size_t print_listint(const listint_t *h);

/* Get the number of elements in the linked list */
size_t listint_len(const listint_t *h);

/* Add a new node with given integer at the beginning of the linked list */
listint_t *add_nodeint(listint_t **head, const int n);

/* Add a new node with given integer at the end of the linked list */
listint_t *add_nodeint_end(listint_t **head, const int n);

/* Free the entire linked list */
void free_listint(listint_t *head);

/* Free the entire linked list and set the head to NULL */
void free_listint2(listint_t **head);

/* Remove the first node from the linked list and return its data */
int pop_listint(listint_t **head);

/* Get the node at the specified index in the linked list */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);

/* Get the sum of all the integers in the linked list */
int sum_listint(listint_t *head);

/* Insert a new node with the given integer at the specified index in the linked list */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n);

/* Delete the node at the specified index from the linked list */
int delete_nodeint_at_index(listint_t **head, unsigned int index);

/* Reverse the order of the linked list */
listint_t *reverse_listint(listint_t **head);

/* Print the elements of the linked lists safely (handles loops) */
size_t print_listint_safe(const listint_t *head);

/* Free the entire linked lists safely (handles loops) */
size_t free_listint_safe(listint_t **h);

/* Find the starts of a loop in the linked list */
listint_t *find_listint_loop(listint_t *head);

#endif

