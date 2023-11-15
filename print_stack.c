#include "monty.h"
/**
 * print_stack - prints all elements of a doubly linked list
 * @h: head of the doubly linked list
 *
 * Return: the number of nodes in the list
*/
size_t print_stack(const stack_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}
	return (count);
}
