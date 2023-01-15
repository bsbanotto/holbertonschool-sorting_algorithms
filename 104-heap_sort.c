#include "sort.h"

/**
 * heap_sort - Implementation of sift-down heap sort algorithm
 * @array: given array of integers to sort
 * @size: size of given array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int i = size / 2 - 1;
	int j = size - 1;

	for (; i >= 0; i--)
	{
		heapify(array, size, i, size);
	}
	for (; j >= 0; j--)
	{
		swap(&array[0], &array[j]);
		if (j > 0)
		{
			/* printf("Print inside heap sort\n"); */
			print_array(array, size);
		}
		heapify(array, size, 0, j);
	}
}

/**
 * heapify - Builds a binary heap
 * @array: Array to turn into a binary heap
 * @size: Size of array to turn into a heap
 * @i: index of array element
 * @value: value of root of tree
 *
 * Return: Void
 */
void heapify(int *array, int size, int i, int value)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < value && array[left] > array[largest])
		largest = left;

	if (right < value && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, size, largest, value);
	}
}

/**
 * swap - swaps position of two elements in a binary tree
 * @a: First element
 * @b: Second element
 *
 * Return: Void
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
