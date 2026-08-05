#include "sort.h"

/**
 * lomuto_partition - Partitions the array using Lomuto scheme
 *
 * @array: Array to partition
 * @low: Start index of the partition
 * @high: End index of the partition (pivot index)
 * @size: Size of the whole array (for printing)
 *
 * Return: Index where the pivot finally lands
 */
static int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, tmp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_rec - Recursively sorts partitions of the array
 *
 * @array: Array to sort
 * @low: Start index of the current partition
 * @high: End index of the current partition
 * @size: Size of the whole array (for printing)
 */
static void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quick_sort_rec(array, low, p - 1, size);
		quick_sort_rec(array, p + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto partition)
 *
 * @array: Array to sort
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, (int)size - 1, size);
}
