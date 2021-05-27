#include "lists.h"

/**
 * is_palindrome - is it a palindomawatist
 * @head: head of list to check
 * Return: 1: yes 0: no
 */
int is_palindrome(listint_t **head)
{
	listint_t *tail = *head;

	if (*head == NULL)
		return (1);

	while (tail->next != NULL)
		tail = tail->next;

	return (pal_rec(head, tail));
}

/**
 * pal_rec - checks the palindrome
 * @head: head of list to check
 * @tail: tail of list to check
 * Return: 1 is yes 0 is no
 */
int pal_rec(listint_t **head, listint_t *tail)
{
	listint_t *pretail = *head;

	if (*head == tail)
		return (1);

	if ((*head)->next == tail && (*head)->n == tail->n)
		return (1);

	if ((*head)->n != tail->n)
		return (0);

	while (pretail->next != tail)
		pretail = pretail->next;

	return (pal_rec(&((*head)->next), pretail));
}
