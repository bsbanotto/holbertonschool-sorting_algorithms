#include "sort.h"

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

/**
 * selection_sort - implementation of selection sort algorithm
 * @array: provided array of integers to sort
 * @size: size of provided array
 *
 * Return: Void
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, index;
	int temp, swap = 0;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		temp = array[i];
		for (j = i; j < size; j++)
		{
			if (array[j] < temp)
			{
				temp = array[j];
				index = j;
				swap = 1;
			}
			if ((swap == 1) && (j == size - 1))
			{
				array_swap(array, i, index);
				print_array(array, size);
			}
		}
		swap = 0;
	}
}
