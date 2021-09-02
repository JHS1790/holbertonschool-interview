#include "search_algos.h"

/**
 * advanced_binary - a function that searches for a value
 * in a sorted array of integers
 * @array: array to search
 * @size: number of elements in array
 * @value: value to search for
 * Return: index of found value
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i, offset = 0;
	int ret_value;

	/* Null Check */
	if (array == NULL || size == 0)
		return (-1);
	if (size == 1 && array[0] != value)
		return (-1);

	/* Print Array */
	printf("Searching in array:");
	for (i = 0; i < size; i++)
	{
		if (i != 0)
			printf(", ");
		printf("%d", array[i]);
		if (i == size - 1)
			printf("\n");
	}

	/* Actual Binary Search */
	i = (size - 1) / 2;
	if (array[i] == value)
	{
		if (i == 0 || (array[i - 1] < value))
			return (i);
	}
	if (array[i] < value)
	{
		offset += i + 1;
		array += i + 1;
		if (size % 2 != 0)
			i--;
	}
	i++;
	ret_value = advanced_binary(array, i, value);
	if (ret_value != -1)
		return (ret_value + offset);
	return (-1);
}
