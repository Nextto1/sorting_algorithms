#include "sort.h"

/**
 * swap_nodes - It swaps two nodes in the linked list.
 * @h: The head pointer of the doubly-linked list.
 * @n1: The first node to swap pointer
 * @n2: The second node to swap for the list
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list -It sorts a doubly linked list of integers
 * using the correct algorithm.
 * @list: The head of a doubly-linked list of integers pointer
 *
 * Description: It prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *inta, *inset, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (inta = (*list)->next; inta != NULL; inta = temp)
	{
		temp = inta->next;
		inset = inta->prev;
		while (inset != NULL && inta->n < inset->n)
		{
			swap_nodes(list, &inset, inta);
			print_list((const listint_t *)*list);
		}
	}
}
