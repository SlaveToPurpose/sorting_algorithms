#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * swap_func - function to swap integers in function
 * @i: first integet
 * @j: second integer
 */

void swap_func(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}


void bubble_sort(int *array, size_t size);
void swap_func(int *i, int *j);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void swap(int *a, int *b);
size_t lomuto_partition(int *array, size_t low, size_t high);
void quick_sort_recursive(int *array, size_t low, size_t high);
void quick_sort(int *array, size_t size);
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2);

#endif /* SORT_H */
