#include "monty.h"

/**
* mod - modulo of top two elements of the stack.
* @head: address to the top of the stack
* @line_num: line number for opcode
* Return: void
*/
void mod(stack_t **head, unsigned int line_num)
{
	stack_t *current = *head;

	if (*head == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		free_helper(*head, t_inf.arr, t_inf.str);
		fclose(t_inf.f);
		exit(EXIT_FAILURE);
	}
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		free_helper(*head, t_inf.arr, t_inf.str);
		fclose(t_inf.f);
		exit(EXIT_FAILURE);
	}
	current->next->n = current->next->n % current->n;
	*head = current->next;
	free(current);
}
