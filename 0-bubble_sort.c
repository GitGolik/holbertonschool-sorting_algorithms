#include "sort.h"

/**
 * bubble_sort - sorts an array of int in ascending order
 * @array: array to sort
 * @size: size of the array
 * Return: NULL or < 2
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int temp;
	int swapped;

	if ((array == NULL) || (size < 2))
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;

				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;
	}
}
