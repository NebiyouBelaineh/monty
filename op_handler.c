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

/**
 * is_integer - checks if an string is an integer or not
 * @str: string to be checked
 * Return: 1 if it is an integer, 0 otherwise
 */
int is_integer(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0); /*Not integer*/

	if (*str == '+' || *str == '-')
		str++;

	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0); /*Not Integer*/
		str++;
	}
	return (1); /*Is integer*/
}
