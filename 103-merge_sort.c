#include "sort.h"

/**
 * merge - performs the merging and sorting of two arrays
 *
 * @left: left array
 * @right: right array
 * @l_size: size ot the left array
 * @r_size: size ot the right array
 * @array: array to be sorted and merged into
 *
 * Return: void
 */
void merge(int *left, int *right, size_t l_size, size_t r_size, int *array)
{
	size_t i, j, k;

	i = j = k = 0;

	while (i < l_size && j < r_size)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < l_size)
	{
		array[k] = left[i];
		i++;
		k++;
	}
	while (j < r_size)
	{
		array[k] = right[j];
		j++;
		k++;
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t mid, i, left_size, right_size;
	int *left, *right;

	if (size < 2)
		return;
	mid = size / 2;
	left_size = mid;
	right_size = size - mid;

	left = malloc(sizeof(int) * left_size);
	right = malloc(sizeof(int) * right_size);

	for (i = 0; i < mid; i++)
		left[i] = array[i];
	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort(left, left_size);
	merge_sort(right, right_size);
	merge(left, right, left_size, right_size, array);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);
	printf("[Done]: ");
	print_array(array, size);

	free(left);
	free(right);
}
