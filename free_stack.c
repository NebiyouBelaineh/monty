#include "monty.h"

/**
 * free_stack - frees memory for stack_t list
 * @head: head of the list
 *
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *temp, *current = head;

	if (head == NULL)
		return;

	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}
