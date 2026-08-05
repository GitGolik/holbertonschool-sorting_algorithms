#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    listint_t *current, *prev, *next;

    if (!list || !*list || !(*list)->next)
        return;

    current = (*list)->next;

    while (current)
    {
        next = current->next;

        while (current->prev && current->n < current->prev->n)
        {
            prev = current->prev;

            /* relier prev->prev et current */
            if (prev->prev)
                prev->prev->next = current;
            current->prev = prev->prev;

            /* relier current et prev->next */
            if (current->next)
                current->next->prev = prev;
            prev->next = current->next;

            /* relier current et prev */
            current->next = prev;
            prev->prev = current;

            /* mettre à jour la tête si nécessaire */
            if (!current->prev)
                *list = current;

            print_list(*list);
        }

        current = next;
    }
}
