#include "monty.h"
stack_t *add_dnodeint(stack_t **head, const int n);
size_t print_stack(const stack_t *h);

/**
 * push - pushes an integer on top of the stack
 * @stack: address to the top of the stack
 * @line_number: line number for opcode
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	int num;

	if (is_integer(t_inf.token_arg))
		num = atoi(t_inf.token_arg);
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_mem(t_inf.arr);
		free_stack(*stack);
		free(t_inf.str);
		fclose(t_inf.f);
		exit(EXIT_FAILURE);
	}
	add_dnodeint(stack, num);
}

/**
 * pall - prints all the values on the stack from the top of the stack.
 * @stack: address to the top of the stack
 * @line_number: line number for opcode
 * Return: void
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	if (stack == NULL && *stack == NULL)
		return;
	print_stack(*stack);
}

#include "monty.h"

/**
 * pint - prints the value at the top of the stack followed by a newline
 * @head: address to the head of the stack
 * @line_num: line number it orignates from
 * Return: void
*/
void pint(stack_t **head, unsigned int line_num)
{
	if (head != NULL)
		if (*head == NULL)
		{
			fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
			free_stack(*head);
			free_mem(t_inf.arr);
			free(t_inf.str);
			fclose(t_inf.f);
			exit(EXIT_FAILURE);
		}
	printf("%d\n", (*head)->n);
}
