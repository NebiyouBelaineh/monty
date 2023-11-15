#include "monty.h"

/**
* pop_tos - removes the top element from a stack_t list
* @head: address of the head
*/
void pop_tos(stack_t **head)
{
	stack_t *current = *head;

	*head = (*head)->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(current);
}
