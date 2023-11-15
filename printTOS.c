#include "monty.h"

/**
 * print_tos - prints an value on TOS
 * @head: head of the stack
*/
void print_tos(stack_t *head)
{
	printf("%d\n", head->n);
}
