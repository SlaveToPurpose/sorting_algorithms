#include "sort.h"

/**
 * swap_nodes - Swap nodes in a list.
 * @h: A pointer to the head
 * @n1: A pointer to the first node
 * @n2: The second node
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;

	if (n2->next != NULL)
		n2->next->prev = *n1;

	n2->prev = (*n1)->prev;
	n2->next = *n1;

	if ((*n1)->prev != NULL)
	{
		(*n1)->prev->next = n2;
	}
	else
	{
		*h = n2;
	}
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *count, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	for (count = (*list)->next; count != NULL; count = temp)
	{
		temp = count->next;
		insert = count->prev;
		while (insert != NULL && count->n < insert->n)
		{
			swap_nodes(list, &insert, count);
			print_list((const listint_t *)*list);
		}
	}
}
