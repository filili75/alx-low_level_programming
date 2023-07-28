#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - Adds a new node at the end of a linked list.
 * @head: Double pointer to the list_t list where the new node will be added.
 * @str: string to be stored in the new node.
 *
 * Return: Address of the new element (the new node), or NULL if it fails to allocate memory.
 */
list_t *add_node_end(list_t **head, const char *str)
{
    list_t *new_node;
    list_t *temp = *head;
    unsigned int len = 0;

    while (str[len])
        len++;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(list_t));
    if (!new_node)
        return (NULL);

    /* Duplicate the input string */
    new_node->str = strdup(str);
    if (!new_node->str)
    {
        /* Free the new node if strdup fails */
        free(new_node);
        return (NULL);
    }

    /* Set the length of the string and the next pointer of the new node */
    new_node->len = len;
    new_node->next = NULL;

    /* If the list is empty, make the new node the head */
    if (*head == NULL)
    {
        *head = new_node;
        return new_node;
    }

    /* Traverse to the end of the list and add the new node there */
    while (temp->next)
        temp = temp->next;

    temp->next = new_node;

    return new_node;
}
