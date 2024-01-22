#include "sort.h"

/**
 * insertion_sort_list - inserts unsorted list into sorted lists
 * @list: pointer to doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *x, *y, *node;

	if (list == NULL || !(*list) || (*list)->next == NULL)
		return;
	x = (*list)->next;
	node = x->next;
	while (x)
	{
		if (x->n < x->prev->n)
		{
			y = x->prev;
			while (y && (y->n > x->n))
			{
				if (!(y->prev))
				{
					y->prev = x;
					x->prev->next = x->next;
					if (x->next)
						x->next->prev = x->prev;
					x->next = y;
					x->prev = NULL;
					*list = x;
				}
				else
				{
					x->prev->next = x->next;
					if (x->next)
						x->next->prev = x->prev;
					y->next->prev = x;
					x->prev = y->prev;
					y->prev = x;
					x->next = y;
				}
				print_list(*list);
				y = x->prev;
			}
		}
		x = node;
		x ? (node = x->next) : (node = NULL);
	}
}
