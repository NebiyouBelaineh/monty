#include "monty.h"

/**
 * add_dnodeint -  adds a new node at the beginning of a stack_t list
 * @head: address of the head of the doubly linked list
 * @n: the data the new node will store
 *
 * Return: address of the new element or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;

	if (*head == NULL)/*if list is empty*/
	{
		new_node->next = NULL;
		*head = new_node;
		return (new_node);
	}
	/*if list not empty*/
	(*head)->prev = new_node;/*first node prev points to new_node*/
	/*new_node next pointer points to the first node*/
	new_node->next = *head;
	*head = new_node;/*head node points to the new_node*/
	return (new_node);
}
