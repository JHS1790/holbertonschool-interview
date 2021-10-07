#include "search.h"

/**
 * linear_skip -  a function that searches for a value in
 *                a sorted skip list of integers.
 *
 * @list: a pointer to the head of the skip list to search in
 * @value: the value to search for
 *
 * Return: pointer first node where value is located or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *first_node, *second_node;

	if (!list)
		return (NULL);
	first_node = list;
	while (first_node)
	{
		if (first_node->express == NULL)
		{
			for (second_node = list; second_node; second_node = second_node->next)
				if (second_node->next == NULL)
				{
					printf("Value found between indexes [%lu] and [%lu]\n",
					       first_node->index, second_node->index);
					break;
				}
			break;
		}
		if (first_node->express->n >= value)
		{
			second_node = first_node->express;
			printf("Value checked at index [%lu] = [%d]\n",
					second_node->index, second_node->n);
			printf("Value found between indexes [%lu] and [%lu]\n",
			       first_node->index, second_node->index);
			break;
		}
		first_node = first_node->express;
		printf("Value checked at index [%lu] = [%d]\n",
				first_node->index, first_node->n);
	}

	return (check_inbetween(first_node, value));
}

/**
 * check_inbetween -  searches for a value
 *
 * @node: is a pointer to the next list to search in
 * @value: is the value to search for
 *
 * Return: pointer first node where value is located or NULL
 */
skiplist_t *check_inbetween(skiplist_t *node, int value)
{
	for (; node; node = node->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		if (node->n == value)
			return (node);
	}
	return (NULL);
}
