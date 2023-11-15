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

/**
 * pchar - prints the ascii character equivalent for the integer at the TOS
 * followed by a newline
 * @head: address to the head of the stack
 * @line_num: line number it orignates from
 * Return: void
 */
void pchar(stack_t **head, unsigned int line_num)
{
	if (head != NULL)
		if (*head == NULL)
		{
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
			free_helper(*head, t_inf.arr, t_inf.str);
			fclose(t_inf.f);
			exit(EXIT_FAILURE);
		}
	if ((*head)->n >= 33 && (*head)->n <= 126)
		printf("%c\n", (*head)->n);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		free_helper(*head, t_inf.arr, t_inf.str);
		fclose(t_inf.f);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - prints the string starting at the TOS, followed by a new line.
 * followed by a newline
 * @head: address to the head of the stack
 * @line_num: line number it orignates from
 * Return: void
 */
void pstr(stack_t **head, __attribute__((unused)) unsigned int line_num)
{
	stack_t *current;

	if (head != NULL)
		if (*head == NULL)
		{
			putchar('\n');
			return;
		}
	current = *head;
	while (current != NULL)
	{
		if ((current)->n >= 33 && (*head)->n <= 126)
			printf("%c", (current)->n);
		else
			break;
		current = current->next;
	}
	putchar('\n');
}
/**
 * rotl - rotates the stack to the top.
 * @head: address to the head of the stack
 * @line_num: line number it orignates from
 * Return: void
 */
void rotl(__attribute__((unused)) stack_t **head, __attribute__((unused))
unsigned int line_num)
{
	stack_t *temp;

	if (head != NULL)
	{
		if (*head == NULL)
			return;
	}
	temp = *head;
	*head = (*head)->next;
	add_node_end(head, temp->n);
	free(temp);
}

/**
 * rotr - rotates the stack to the down.
 * @head: address to the head of the stack
 * @line_num: line number it orignates from
 * Return: void
 */
void rotr(__attribute__((unused)) stack_t **head, __attribute__((unused))
unsigned int line_num)
{
	stack_t *current;

	if (head != NULL)
	{
		if (*head == NULL)
			return;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	add_dnodeint(head, current->n);
	current->prev->next = NULL;
	free(current);
}
