#include "sort.h"

/**
 * lomuto_partition - Partition the array and return the pivot index
 * using Lomuto´s partition shceme.
 *
 * @array: Array to be sorted.
 * @low: Lower index of the partition.
 * @high: Upper index of the partition (pivot).
 * @size: Size of the array.
 *
 * Return: Index of the pivot after partition.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{

	int pivot = array[high];
	int i = low - 1; int j;
	int temp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	print_array(array, size);
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursively sorts the array using Quick Sort
 *
 * @array: Array to be sorted.
 * @low: Lower index of the partition.
 * @high: Upper index of the partition.
 * @size: Size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order 
 * using the quick sort algorithm.
 *
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

