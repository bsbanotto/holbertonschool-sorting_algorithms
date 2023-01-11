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
	/* print_my_array(array, 0, size / 2); */
	copy_array(array, 0, size, temp_array);
	print_my_array(temp_array, 0, size);
	recur_split(temp_array, 0, size, array);
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
	int i;

	printf("Printed with print_my_array:\n");

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

/**
 * recur_split - Splits the array recursively until it is of size 1
 * @temp_array: Temporary array, copy of given array
 * @array: Given array to sort
 * @start: Starting index of array to split
 * @end: End index of array to split
 */
void recur_split(int *temp_array, int start, int end, int *array)
{
	int mid = (end + start) / 2;

	if (end - start <= 1) /*Gets out if array has length of 1*/
	{
		print_my_array(array, start, end);
		return;
	}

	recur_split(array, start, mid, temp_array);
	recur_split(array, mid, end, temp_array);
}
