#include "sort.h"

/**
 * swap_list - swap two nodes of linked list
 * @h: Pointer to the head of linked list
 * @node_1: A pointer to the first node to be swappwd
 * @node_2: pointer to the second node
 * Return: void.
 */
void swap_list(listint_t **h, listint_t **node_1, listint_t *node_2)
{
	(*node_1)->next = node_2->next;
	if (node_2->next != NULL)
		node_2->next->prev = *node_1;
	node_2->prev = (*node_1)->prev;
	node_2->next = *node_1;
	if ((*node_1)->prev != NULL)
		(*node_1)->prev->next = node_2;
	else
		*h = node_2;
	(*node_1)->prev = node_2;
	*node_1 = (node_2)->prev;
}

/**
 * insertion_sort_list - function that sorts a linked list of integers
 * in ascending order using the inertion algorithm
 * @list : Doubly Linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *n_node = NULL, *ptr, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (n_node = (*list)->next; n_node != NULL; n_node = temp)
	{
		temp = n_node->next;
		ptr = n_node->prev;
		while (ptr != NULL && n_node->n < ptr->n)
		{
			swap_list(list, &ptr, n_node);
			print_list(*list);
		}
	}
}
