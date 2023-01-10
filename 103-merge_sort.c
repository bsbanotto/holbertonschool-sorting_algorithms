#include "sort.h"

/**
 * merge_sort - Implementation of top-down merge sort algorithm
 * @array: pointer to array of integers to be sorted
 * @size: size of given array
 *
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	int *temp_array = malloc(sizeof(array[0]) * size);
	print_my_array(array, 0, size / 2);
	copy_array(array, 0, size, temp_array);
	print_my_array(temp_array, 0, size);
	free(temp_array);
}

/**
 * print_my_array - Prints an array between two indeces
 * @array: Array to print
 * @start: Starting index of array to print
 * @end: Ending index of array to print
 *
 * Return: void
 */

void print_my_array(int *array, int start, int end)
{
	int i = start;

	printf("Printed with helper function:\n");

	for (i = start; i < end; i++)
	{
		printf("%d", array[i]);
		if (i < end - 1)
		{
			printf(", ");
		}
		else
			printf("\n");
	}
}

/**
 * copy_array - Copies from array to temp_array
 * @array: Original Array
 * @start_index: Starting index to copy
 * @end_index: End index to copy
 * @temp_array: Holds the copied array
 *
 * Return: void
 */
void copy_array(int *array, int start_index, int end_index, int *temp_array)
{
	int i;

	for (i = start_index; i < end_index; i++)
		temp_array[i] = array[i];
}
