#include "sort.h"

/**
 * bubble_sort - sorts an array in ascending order
 * @array: poniter to array to be sorted
 * @size: size of array
 */

void swap_func(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_func(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
