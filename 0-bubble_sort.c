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
 * bubble_sort - sort int arr in ascending order using bubble sort
 * @array: array to sort
 * @size: number of elements in array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, newnum, temp;

	if (size < 2)
		return;

	do {
		newnum = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				array_swap(array, i - 1, i);
				newnum = i;
				print_array(array, size);
			}
		}
		temp = newnum;
	} while (temp >= 1);
}
