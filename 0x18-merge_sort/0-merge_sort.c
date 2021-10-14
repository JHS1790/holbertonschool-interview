#include "sort.h"

/**
 * merge_sort - a function that sorts an array of integers in
 * ascending order using the Merge Sort algorithm
 *
 * @array: array to sort
 * @size: length of array
 */
void merge_sort(int *array, size_t size)
{
	int *left, *right, *start = array, top;
	size_t left_size = size / 2, right_size = size / 2 + size % 2;
	static int *work_array, i, j;

	if (array == NULL || size <= 1)
		return;
	top = 0;
	if (work_array == NULL)
	{
		top = 1;
		work_array = malloc(sizeof(int) * size);
	}
	merge_sort(array, left_size);
	merge_sort(array + left_size, right_size);
	left = array;
	right = array + left_size;
	printa(left, right, left_size, right_size);
	for (i = 0; left_size > 0 && right_size > 0; i++)
	{
		if (*left < *right)
		{
			work_array[i] = *left;
			left++;
			left_size--;
		}
		else
		{
			work_array[i] = *right;
			right++;
			right_size--;
		}
	}
	i--;
	for (j = i + 1; left_size; left_size--, left++, j++)
		array[j] = *left;
	for (j = i + 1; right_size; right_size--, right++, j++)
		array[j] = *right;
	for (; i >= 0; i--)
		array[i] = work_array[i];
	printf("[Done]: ");
	print_array(start, size);
	if (top)
		free(work_array);
}

void printa(int *left, int *right, size_t left_size, size_t right_size)
{
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);
}
