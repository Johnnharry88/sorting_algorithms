#include "sort.h"
/**
 * swap_list - swaps linked list
 * @node_1: pointer to the first node to be swapped.
 * @node_2: pointer to the second node to be swapped.
 * @list: list to be sort.
 * Return: void.
 */
void swap_list(listint_t *node_1, listint_t *node_2, listint_t **list)
{
	if (!(node_1->prev))
	{
		node_1->next = node_2->next;
		if (node_2->next)
			node_2->next->prev = node_1;
		node_2->next = node_1;
		node_2->prev = NULL;
		node_1->prev = node_2;
		*list = node_2;
	}
	else
	{
		node_2->prev->next = node_2->next;
		if (node_2->next)
			node_2->next->prev = node_2->prev;
		node_1->prev->next = node_2;
		node_2->prev = node_1->prev;
		node_1->prev = node_2;
		node_1->next = node_2;
	}
}

/**
 * cocktail_sort_list - inserts unsorted side to sorted side
 * @list: Doubly linked list to be sorted
 * Return: void.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *x, *n_node;
	int flag;

	if (list == NULL || !(*list) || (*list)->next == NULL)
		return;
	x = (*list);
	do {
		flag = 0;
		while (x->next)
		{
			n_node = x->next;
			if (n_node && x->n > n_node->n)
			{
				swap_list(x, n_node, list);
				flag = 1;
				print_list((*list));
			}
			else
				x = x->next;
		}
		x = x->prev;
		while (x->prev)
		{
			n_node = x->prev;
			if (n_node && x->n < n_node->n)
			{
				swap_list(n_node, x, list);
				flag = 1;
				print_list((*list));
			}
			else
				x = x->prev;
		}
		if (!flag)
			break;
		x = x->next;
	} while (list);
}
