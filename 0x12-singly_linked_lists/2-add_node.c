#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of a linked list.
 * @head: Double pointer to the list_t list where the new node will be added.
 * @str: New string to be stored in the node.
 *
 * Return: The address of the new element (the new node), or NULL if it fails to allocate memory.
 */

list_t *add_node(list_t **head, const char *str)
{
    list_t *new_node;
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

    /* Set the length of the string and link the new node to the list */
    new_node->len = len;
    new_node->next = *head;
    *head = new_node;

    return new_node;
}
