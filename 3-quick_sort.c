#include "sort.h"

/**
 * swap - swaps two elements in array
 * @array: element of array to swap
 * @array2: element of array to swap
 */
void swap(int *array, int *array2)
{
	int tmp;

	tmp = *array;
	*array = *array2;
	*array2 = tmp;
}

/**
 * lomuto_partition - Partition the array and return the pivot index
 * using Lomuto´s partition scheme.
 *
 * @array: Array to be sorted.
 * @low: Lower index of the partition.
 * @high: Upper index of the partition (pivot).
 * @size: Size of the array.
 *
 * Return: Index of the pivot after partition.
 */
int lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t i, j;
	int pivot;

	pivot = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		swap(&array[high], &array[i + 1]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - sorts a partition of an array of integers
 * @array: array to sort
 * @low: lowest index of the partition to sort
 * @high: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: void
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);

	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
