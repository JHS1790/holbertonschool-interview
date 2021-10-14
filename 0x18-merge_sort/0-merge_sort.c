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
	int *left, *right, top = 0;
	size_t left_size = size / 2, right_size = size / 2 + size % 2;
	static int *work_array, i, j;

	if (array == NULL || size <= 1)
		return;
	if (work_array == NULL)
	{
		top = 1;
		work_array = malloc(sizeof(int) * size);
	}
	merge_sort(array, left_size);
	merge_sort(array + left_size, right_size);
	left = array;
	right = just_for_betty(array, left_size, right_size);
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
	printb(array, size);
	if (top)
		free(work_array);
}

/**
 * printa - line reducer
 * @left: betty please
 * @right: stop being
 * @left_size: such a
 * @right_size: pedantic program
 */
void printa(int *left, int *right, size_t left_size, size_t right_size)
{
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);
}

/**
 * printb - line reducer
 * @array: please
 * @size: end my suffering
 */
void printb(int *array, size_t size)
{
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * just_for_betty - line reducer
 * @array: exists literally
 * @left_size: to reduce
 * @right_size: a single line
 * Return: my pacheechees
 */
int *just_for_betty(int *array, size_t left_size, size_t right_size)
{
	int *right = array + left_size;

	printa(array, right, left_size, right_size);
	return (right);
}
