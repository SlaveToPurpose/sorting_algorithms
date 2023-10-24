#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list with insertion
 * @list: Doubly linked list
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *node, *head;

	if (list == NULL)
	{
		return;
	}

	if (*list == NULL)
	{
		return;
	}

	head = *list;

	while (head)
	{
		if (head->next && (head->n > head->next->n))
		{
			temp = head;
			head->next->prev = head->prev;

			if (head->prev)
			{
				head->prev->next = head->next;
			}
			else
			{
				*list = head->next;
			}

			node = head->next;
			temp->prev = NULL;
			temp->next = NULL;
			
			if (node->next)
			{
				temp->next = node->next;
				node->next->prev = temp;
				node->next = temp;
				temp->prev = node;
			}
			else
			{
				node->next = temp;
				temp->prev = node;
			}

			print_list(*list);
			head = *list;
			continue;
		}
		head = head->next;
	}
}
