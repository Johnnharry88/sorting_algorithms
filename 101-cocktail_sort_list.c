#include "sort.h"
/**
 * swap_list - swaps linked list
 * @node: pointer to the first node to be swapped.
 * @list: list to be sort.
 * Return: listint_t.
 */
listint_t *swap_list(listint_t *node, listint_t **list)
{
	listint_t *ptr_1 = node->prev, *ptr_2 = node;

	ptr_1->next = ptr_2->next;
	if (ptr_2->next)
		ptr_2->next->prev = ptr_1;
	ptr_2->next = ptr_1;
	ptr_2->prev = ptr_1->prev;
	ptr_1->prev = ptr_2;
	if (ptr_2->prev)
		ptr_2->prev->next = ptr_2;
	else
		*list = ptr_2;
	return (ptr_2);
}

/**
 * cocktail_sort_list - inserts unsorted side to sorted side
 * @list: Doubly linked list to be sorted
 * Return: void.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *x;
	int flag = 1;

	if (list == NULL || !(*list) || (*list)->next == NULL)
		return;
	x = (*list);
	while (flag == 1)
	{
		flag = 0;
		while (x->next)
		{
			if (x->n > x->next->n)
			{
				x = swap_list(x->next, list);
				flag = 1;
				print_list((*list));
			}
			x = x->next;
		}
		if (flag == 0)
			break;

		while (x->prev)
		{
			if (x->n < x->prev->n)
			{
				x = swap_list(x, list);
				flag = 1;
				print_list((*list));
			}
			else
				x = x->prev;
		}

	}
}
