#include "sort.h"

/**
 * selection_sort - sort an array if int in order
 * @array: pointer to the first element of the array to sort
 * @size: number of elements in the array
 * Return: no return
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int tmp;

	if ((!array) || (size < 2))
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}

			if (min_index != 1)
			{
				tmp = array[i];
				array[i] = array[min_index];
				array[min_index] = tmp;

				print_array(array, size);
			}
		}
	}
}
