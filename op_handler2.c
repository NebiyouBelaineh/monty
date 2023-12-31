#include "monty.h"

/**
* add - adds the top two elements of the stack.
* @head: address to the top of the stack
* @line_num: line number for opcode
* Return: void
*/
void add(stack_t **head, unsigned int line_num)
{
	stack_t *current = *head;

	if (*head == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		free_helper(*head, t_inf.arr, t_inf.str);
		fclose(t_inf.f);
		exit(EXIT_FAILURE);
	}
	current->next->n = current->n + current->next->n;
	*head = current->next;
	free(current);
}

/**
 * nop - doesn’t do anything.
 * @stack: address to the top of the stack
 * @line_number: line number for opcode
 * Return: void
 */
void nop(__attribute__((unused)) stack_t **stack, __attribute__((unused))
unsigned int line_number)
{
}

/**
* sub - subtracts the top two elements of the stack.
* @head: address to the top of the stack
* @line_num: line number for opcode
* Return: void
*/
void sub(stack_t **head, unsigned int line_num)
{
	stack_t *current = *head;

	if (*head == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		free_helper(*head, t_inf.arr, t_inf.str);
		fclose(t_inf.f);
		exit(EXIT_FAILURE);
	}
	current->next->n = current->next->n - current->n;
	*head = current->next;
	free(current);
}

/**
* divide - divides the top two elements of the stack.
* @head: address to the top of the stack
* @line_num: line number for opcode
* Return: void
*/
void divide(stack_t **head, unsigned int line_num)
{
	stack_t *current = *head;

	if (*head == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
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
	current->next->n = current->next->n / current->n;
	*head = current->next;
	free(current);
}

/**
* mul - multiplies the top two elements of the stack.
* @head: address to the top of the stack
* @line_num: line number for opcode
* Return: void
*/
void mul(stack_t **head, unsigned int line_num)
{
	stack_t *current = *head;

	if (*head == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		free_helper(*head, t_inf.arr, t_inf.str);
		fclose(t_inf.f);
		exit(EXIT_FAILURE);
	}
	current->next->n = current->next->n * current->n;
	*head = current->next;
	free(current);
}
