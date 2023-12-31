#include "sort.h"

/**
 * swap - Swap two integers in an array
 * @a: The first integer to swap
 * @b: The second integer to swap
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Order according to the lomuto partition scheme
 * @array: The array of integers
 * @low: The starting index of the subset to order
 * @high: The ending index of the subset to order
 *
 * Return: Final partition index
 */

size_t lomuto_partition(int *array, size_t low, size_t high)
{
	int pivot = array[high];
	size_t j;
	size_t i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			swap(&array[i], &array[j]);
			print_array(array, high + 1);
		}
		i++;
	}

	swap(&array[i + 1], &array[high]);
	print_array(array, high + 1);
	return (i + 1);
}

/**
 * quick_sort_recursive -  perform Quick Sort using the Lomuto partition scheme
 * @array: The array of integers.
 * @low: The starting index of the subset to order.
 * @high: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */

void quick_sort_recursive(int *array, size_t low, size_t high)
{
	if (low < high)
	{
		size_t partition_index = lomuto_partition(array, low, high);

		quick_sort_recursive(array, low, partition_index - 1);
		quick_sort_recursive(array, partition_index + 1, high);
	}
}

/**
 * quick_sort - function to call the recursive Quick Sort function
 * @array: An array of integers.
 * @size: The size of the array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
	{
		return;
	}

	quick_sort_recursive(array, 0, size - 1);
}
