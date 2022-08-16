#include "sort.h"

/**
 * quick_sort - Implementation of Quicksort algorithm
 * @array: pointer to array of integers
 * @size: size of array
 *
 * Return: Void
 */

void quick_sort(int *array, size_t size)
{
	partition(array, 0, (int)size - 1, size);
}

/**
 * partition - creates partition and sorts recursively
 * @array: array to sort
 * @low: index of starting element of list
 * @high: index of last element of list
 * @size: size of original array
 */
void partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i, j = low;

	if (low >= high)
		return;

	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			if (i != j)
			{
				array_swap(array, i, j);
				print_array(array, size);
			}
			j++;
		}
	}
	if (j != high)
	{
		array_swap(array, high, j);
		print_array(array, size);
	}

	partition(array, low, j - 1, size);
	partition(array, j + 1, high, size);
}

/**
 * array_swap - swaps two integers in an array
 * @array: array to be sorted
 * @a: index of first integer
 * @b: index of second integer
 *
 * Return: Void
 */

void array_swap(int *array, int a, int b)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}
