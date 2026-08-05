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

			if (prev->prev)
				prev->prev->next = current;
			current->prev = prev->prev;

			if (current->next)
				current->next->prev = prev;
			prev->next = current->next;

			current->next = prev;
			prev->prev = current;

			if (!current->prev)
				*list = current;

			print_list(*list);
		}

		current = next;
	}
}
