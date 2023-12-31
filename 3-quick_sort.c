#include "sort.h"

/**
 * swap - swaps two elements
 *
 * @a: first element
 * @b: second element
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - performs the partitioning of the qsort algorithm
 *
 * @array: array to be sorted
 * @start: start of the array
 * @end: end of the array
 * @size: size of the array
 *
 * Return: pivot index
 */
int partition(int *array, int start, int end, size_t size)
{
	int pivot, p_index, i;

	pivot = array[end];
	p_index = start;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			swap(&array[i], &array[p_index]);
			if (p_index != i)
				print_array(array, size);
			p_index++;
		}
	}
	swap(&array[p_index], &array[end]);
	if (p_index != end)
		print_array(array, size);
	return (p_index);
}

/**
 * q_sort - sorts an array using quick sort
 *
 * @array: array to be sorted
 * @start: start index
 * @end: end index
 * @size: size of the array
 *
 * Return: void
 */
void q_sort(int *array, int start, int end, size_t size)
{
	int p_index;

	if (start < end)
	{
		p_index = partition(array, start, end, size);
		q_sort(array, start, p_index - 1, size);
		q_sort(array, p_index + 1, end, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm (Lomuto partition scheme)
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	q_sort(array, 0, size - 1, size);
}
