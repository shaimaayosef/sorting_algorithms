#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                        using the Insertion sort algorithm
 *
 * @list: A pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    if (list == NULL || *list == NULL)
        return;

    current = (*list)->next;

    while (current != NULL)
    {
        temp = current->next;

        while (current->prev != NULL && current->n < current->prev->n)
        {
            /* Swap nodes if they are in the wrong order */
            current->prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = current->prev;

            current->next = current->prev;
            current->prev = current->prev->prev;

            if (current->prev != NULL)
                current->prev->next = current;

            current->next->prev = current;

            /* Update the head of the list if needed */
            if (current->prev == NULL)
                *list = current;

            /* Print the list after each swap */
            print_list(*list);
        }

        current = temp;
    }
}
