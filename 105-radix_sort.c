#include "sort.h"

/**
 * radix_sort - Implementation of LSD Radix Sort
 * @array: Pointer of array of integers, all values >= 0
 * @size: Size of array to be sorted
 *
 * Return: Void
 */

void radix_sort(int *array, size_t size)
{
	int max, place;

	if ((array != NULL) && (size > 1))
	{
		max = getMax(array, size);
		for (place = 1; max / place > 0; place *= 10)
		{
			countingSort(array, size, place);
			print_array(array, size);
		}
	}
}

/**
 * getMax - Gets the largest element in a given array
 * @array: Array to look in=
 * @size: Size of array
 *
 * Return: Max in a given array
 */

int getMax(int *array, int size)
{
	int max = array[0], i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * countingSort - Sorts elements based on place value
 * @array: Array to sort
 * @size: Size of array
 * @place: Place position to sort on
 *
 * Return: Void
 */

void countingSort(int *array, int size, int place)
{
	int max, i, *output, *count;

	max = (array[0] / place) % 10;
	output = malloc(sizeof(array[0]) * (int)size);
	count = malloc(sizeof(array[0]) * (int)size);

	for (i = 1; i < size; i++)
	{
		if (((array[i] / place) % 10) > max)
			max = array[i];
	}

	for (i = 0; i < max; ++i)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
