#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * find_listint_loop - is there a loop in the array?
 * @head: head of the list to check
 * Return: address of the node where the loop starts.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow_p, *fast_p;

	if (head == NULL)
		return (NULL);

	slow_p = head;
	fast_p = head;
	while (0 == 0)
	{
		if (fast_p->next == NULL || fast_p->next->next == NULL)
			return (NULL);
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (fast_p == slow_p)
			break;
	}
	slow_p = head;
	while (0 == 0)
	{
		if (fast_p == slow_p)
			return (fast_p);
		fast_p = fast_p->next;
		slow_p = slow_p->next;
	}
}
