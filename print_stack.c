#include "monty.h"
/**
 * print_stack - prints all elements of a doubly linked list
 * @h: head of the doubly linked list
 *
 * Return: the number of nodes in the list
*/
void print_stack(stack_t *h)
{
	stack_t *current = h;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
