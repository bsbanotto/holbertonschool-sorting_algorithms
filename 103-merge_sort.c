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
	/* print_my_array(temp_array, 0, size); */
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

	/* printf("Printed with print_my_array:\n"); */

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
 *
 * Return: Void
 */
void recur_split(int *temp_array, int start, int end, int *array)
{
	int mid = (end + start) / 2;

	if (end - start <= 1) /*Gets out if array has length of 1*/
	{
		/* print_my_array(array, start, end); */
		return;
	}

	recur_split(array, start, mid, temp_array);
	recur_split(array, mid, end, temp_array);

	time_to_merge(temp_array, start, mid, end, array);
}

/**
 * time_to_merge - Takes all of the split arrays, compares and merges
 * @array: Given array, one element long to start
 * @start: starting index of array
 * @mid: middle index of array
 * @end: ending index of rarry
 * @temp_array: Array to be returned to print
 *
 * Return: Void
 */
void time_to_merge(int *array, int start, int mid, int end, int *temp_array)
{
	int i = start; /*Used to index through left and right runs*/
	int j = mid; /*Used as end point for left run*/
	int k = start; /*Used to index through temp_array, which is sorted*/

	for (k = start; k < end; k++)
	{
		if (i < mid && (j >= end || array[i] <= array[j]))
		{
			temp_array[k] = array[i];
			i++;
		}
		else
		{
			temp_array[k] = array[j];
			j++;
		}
	}

	printf("Merging...\n[left]: ");
	print_my_array(array, start, mid);
	printf("[right]: ");
	print_my_array(array, mid, end);
	printf("[Done]: ");
	print_my_array(temp_array, start, end);
}
