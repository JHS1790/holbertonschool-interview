#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: list to check.
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *last;
	listint_t *next;

	if (list == NULL)
	{
		return (0);
	}

	last = list;
	next = list->next;

	while (last != next)
	{
		if (next == NULL || (*next).next == NULL)
		{
			return (0);
		}
		last = last->next;
		next = next->next->next;
	}
	
	return (1);
}
