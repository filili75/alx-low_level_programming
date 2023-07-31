#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node in a linked list at a given position.
 * @list_head: Pointer to the pointer of the first node in the list.
 * @index: Index where the new node is added.
 * @data: Data to insert in the new node.
 *
 * Return: Pointer to the new node, or NULL if the insertion fails.
 */
listint_t *insert_nodeint_at_index(listint_t **list_head, unsigned int index, int data)
{
    unsigned int e;
    listint_t *new_node;
    listint_t *current_node = *list_head;

    new_node = malloc(sizeof(listint_t));
    if (!new_node || !list_head)
        return (NULL);

    new_node->n = data;
    new_node->next = NULL;

    if (index == 0)
    {
        new_node->next = *list_head;
        *list_head = new_node;
        return (new_node);
    }

    for (e = 0; current_node && e < index; e++)
    {
        if (e == index - 1)
        {
            new_node->next = current_node->next;
            current_node->next = new_node;
            return (new_node);
        }
        else
            current_node = current_node->next;
    }

    return (NULL);
}

