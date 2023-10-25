#include "sort.h"

/**
 * selection_sort - sorts array using Selection sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */

void selection_sort_custom(int *array, size_t size)
{
    size_t i, j, indx;
    int temp;

    for (i = 0; i < size - 1; i++)
    {
	indx = i;
	for (j = i + 1; j < size; j++)
	{
	    if (array[j] < array[indx])
	    {
		indx = j;
	    }
	}
	if (indx == i)
	{
		continue;
	}
	else
	{
		temp = array[indx] + array[i];
		array[indx] = temp - array[indx];
		array[i] = temp - array[i];

		print_array(array, size);
	}
    }
}
