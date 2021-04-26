#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts node into a listint_t list
 * @head: pointer to head of list
 * @number: data for new node
 * Return: new node created
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t* new_node = (listint_t *) malloc(sizeof(listint_t));
    listint_t* current;
    new_node->n = number;
    if (*head == NULL || (*head)->n >= new_node->n)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else 
    {
        current = *head;
        while (current->next != NULL && current->next->n < new_node->n)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    return (new_node);
}
