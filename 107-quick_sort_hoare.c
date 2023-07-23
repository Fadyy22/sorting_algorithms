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
 * hoare_partition - performs the partitioning of the qsort algorithm
 *
 * @array: array to be sorted
 * @start: start of the array
 * @end: end of the array
 * @size: size of the array
 *
 * Return: pivot index
 */
int hoare_partition(int *array, int start, int end, size_t size)
{
	int pivot, i, j;

	pivot = array[end];
	i = start - 1;
	j = end + 1;
	while (i < j)
	{
		do
			i++;
		while (array[i] < pivot);

		do
			j--;
		while (array[j] > pivot);

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	return (i);
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
		p_index = hoare_partition(array, start, end, size);
		q_sort(array, start, p_index - 1, size);
		q_sort(array, p_index, end, size);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * using the Quick sort algorithm (Hoare partition scheme)
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	q_sort(array, 0, size - 1, size);
}
