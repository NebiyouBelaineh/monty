#include "monty.h"

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
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (stack == NULL && *stack == NULL)
		return;
	print_stack(*stack);
}

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
			free_helper(*head, t_inf.arr, t_inf.str);
			exit(EXIT_FAILURE);
		}
	printf("%d\n", (*head)->n);
}

/**
 * pop - removes the top element of the stack.
 * @head: address to the head of the stack
 * @line_num: line number it orignates from
 * Return: void
 */
void pop(stack_t **head, unsigned int line_num)
{
	if (head != NULL)
		if (*head == NULL)
		{
			fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
			free_helper(*head, t_inf.arr, t_inf.str);
			fclose(t_inf.f);
			exit(EXIT_FAILURE);
		}
	pop_tos(head);
}

/**
 * swap - swaps the top two elements of the stack.
 * @head: address to the top of the stack
 * @line_num: line number for opcode
 * Return: void
 */
void swap(stack_t **head, unsigned int line_num)
{
	int count = 0, temp;
	stack_t *current, *temp1, *temp2;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		free_helper(*head, t_inf.arr, t_inf.str);
		fclose(t_inf.f);
		exit(EXIT_FAILURE);
	}
	if (head != NULL)
		current = *head;
	if (current == current->next)
		return;
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		free_helper(*head, t_inf.arr, t_inf.str);
		fclose(t_inf.f);
		exit(EXIT_FAILURE);
	}
	current = *head;

	temp1 = current;
	temp2 = current->next;

	temp = temp1->n;
	temp1->n = temp2->n;
	temp2->n = temp;
}
